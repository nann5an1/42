/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 13:37:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void childProcess(int in_file, int out_file, int fd[2], char* argv[], char** envp)
{
    int pid1 = fork();
        if(pid1 == 0)
        {
            dup2(in_file, STDIN_FILENO);
            dup2(fd[1], STDOUT_FILENO); //WR_END to STDOUT(1)
            close(fd[0]);
            close(fd[1]);
            close(in_file);
            exec_command(argv[2], envp); //argv[2] = "ls -l"
        }
        int pid2 = fork();
        if(pid2 == 0)
        {
            dup2(fd[0], STDIN_FILENO); //READ_END to STDOUT(0)
            dup2(out_file, STDOUT_FILENO); 
            close(fd[0]);
            close(fd[1]);
            close(out_file);
            exec_command(argv[3], envp);
        }
        waitpid(pid2, NULL, 0);
}
//user compilation --> ./pipex.exe "in_file" "ls -l" "grep hello" "out_file"
int main(int argc, char* argv[], char **envp)
{
    int fd[2];
    int in_file;
    int out_file;
    int i = 0;
    if(argc == 5)
    {            
        if(pipe(fd) < 0)
            errorHandling(1);
        if((access(argv[1], F_OK) < 0))
            errorHandling(2);
        else if(access(argv[1], R_OK) < 0)
            errorHandling(3);
        
        in_file = open(argv[1], O_RDONLY);
        out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        
        if(in_file < 0 || out_file < 0)
            errorHandling(4);
        
        // printf("%d", in_file);
        // printf("%d", out_file);
        childProcess(in_file, out_file, fd, argv, *envp);
        close(fd[0]);
        close(fd[1]);
    }
    else 
        errorHandling(0);
}


    
    //at the very end add waitpid(pid) to wait for pid to finish