/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 23:14:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int firstChild(int in_file, int fd[2], char* argv[], char** envp)
{
    int status;
    int pid1 = fork();
    if(pid1 == 0)
    {
        dup2(in_file, STDIN_FILENO);
        // fprintf(stderr, "Vainpot in first in_file\n");
        dup2(fd[1], STDOUT_FILENO); //WR_END to STDOUT(1)
        // fprintf(stderr, "Vainpot in second in_file\n");
        close(fd[0]);
        close(fd[1]);
        close(in_file);
        // fprintf(stderr, "Vainpot in first closed before exec\n");
        if(exec_command(argv[2], envp) == 1)//argv[2] = "ls -l"
            exit(1);
        exit(0);
        // fprintf(stderr, "Vainpot in first  after exec\n");
    }
    waitpid(pid1, &status, 0);
    if ( WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}


int secChild(int out_file, int fd[2], char* argv[], char** envp)
{
    int pid2 = fork();
    if(pid2 == 0)
    {
        dup2(out_file, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO); //READ_END to STDOUT(0)
        close(fd[0]);
        close(fd[1]);
        close(out_file);
        if(exec_command(argv[3], envp) == 1)
            exit(1);
        exit (0);
    }
    close(fd[0]);
    close(fd[1]);
    int status;
    waitpid(pid2, &status, 0);
    if ( WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}
int main(int argc, char* argv[], char **envp)
{
    int fd[2];
    int in_file;
    int out_file;
    // char buffer[1024];
    if(argc == 5)
    {          
        if(pipe(fd) < 0)
            errorHandling("Piping failed");
        if((access(argv[1], F_OK) < 0))
            errorHandling("File is not accessible");
        else if(access(argv[1], R_OK) < 0)
            errorHandling("File is not readable");
        // fprintf(stderr, "Vainpot is laughing\n");
        // if(strcmp(argv[1], "/dev/urandom") == 0)
        // {
        //     int open_rand = open("/dev/urandom", O_RDONLY);
        //     int read_rand = read(open_rand, buffer, sizeof(buffer));
        //     write(open_rand, buffer, read_rand);
        //     in_file = open("tempfile.txt", O_RDONLY);
        // }
        // else
            in_file = open(argv[1], O_RDONLY);
        // fprintf(stderr, "Vainpot is singing\n");
        out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        // fprintf(stderr, "Vainpot is reading\n");
        if(in_file < 0 || out_file < 0)
            errorHandling("File cannot be opened");
        // fprintf(stderr, "Vainpot before first\n");
        int res1 = firstChild(in_file, fd, argv, envp);
        //fprintf(stderr, "Vainpot before second\n");
        int res2 = secChild(out_file, fd, argv, envp);
        if(res1 == 1 || res2 == 1)
            ft_putstr_fd("Error: Command not found\n" , 2);
        // else
        //     ft_putstr_fd("Error: Command not found\n" , 2);
        
        exit(EXIT_FAILURE);
        close(in_file);
        close(out_file);
    }
    else 
        ft_putstr_fd("Format Error\n", 2);
}

    //at the very end add waitpid(pid) to wait for pid to finish