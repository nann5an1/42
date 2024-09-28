/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:57:18 by nsan              #+#    #+#             */
/*   Updated: 2024/09/28 17:57:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void errorOut()
{
    int error_flag = 0;
    if (!error_flag) 
    {
        fprintf(stderr, "Usage of wrong command.\n");
        error_flag = 1; 
    }
}

int firstChild(int in_file, int fd[2], char* argv[], char** envp)
{
    int pid1 = fork();
    if(pid1 == 0)
    {
        dup2(in_file, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO); //WR_END to STDOUT(1)
        close(fd[0]);
        close(fd[1]);
        close(in_file);
        if(split_join(argv[2], envp) == 1) //argv[2] = "ls -l"   /bin/ls
           errorOut();
    }
    waitpid(pid1, NULL, 0);
    return (0);
}


void secChild(int out_file, int fd[2], char* argv[], char** envp)
{
    int pid2 = fork();
    if(pid2 == 0)
    {
        dup2(out_file, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO); //READ_END to STDOUT(0)
        close(fd[0]);
        close(fd[1]);
        close(out_file);
        if(split_join(argv[3], envp) == 1)
            errorOut();
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid2, NULL, 0);
}

int main(int argc, char* argv[], char **envp)
{
    int fd[2];
    int in_file;
    int out_file;
    if(argc == 5)
    {          
        if(pipe(fd) < 0)
            errorHandling("Piping failed");
        if((access(argv[1], F_OK) < 0))
            errorHandling("File is not accessible");
        else if(access(argv[1], R_OK) < 0)
            errorHandling("File is not readable");
        in_file = open(argv[1], O_RDONLY);
        out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if(in_file < 0 || out_file < 0)
            errorHandling("File cannot be opened");
        if(firstChild(in_file, fd, argv, envp) == 1)
            exit(EXIT_FAILURE);
        secChild(out_file, fd, argv, envp);
    }
    else 
        fprintf(stderr, "Error: Number of total arguments must be 5\n");
}

    //at the very end add waitpid(pid) to wait for pid to finish