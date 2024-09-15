/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/09/13 21:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void exec_command(char* cmd)
{    
    char *const av[] = ft_split(cmd);
    const char* programDir = programSearch(av[0]);
    const char* envp[] = {NULL}; //path to the program i want to execute
    if(execve(programDir, av, envp) < 0)
        perror("Error Executing");
    execve(programDir, av, envp);
    printf("Execute the command");         
}

//user compilation --> ./pipex.exe "in_file" "ls -l" "grep hello" "out_file"
int main(int argc, char** argv)
{
    int fd[2];
    int in_file;
    int out_file;
    if(argc == 5)
    {
        //creation of pipe
        if(pipe(fd) < 0){
            perror("Error in creating pipe");
            exit(EXIT_FAILURE);
        }

        //opening of files
        in_file = open(argv[1], O_RDONLY);
        out_file = open(argv[4], O_WRONLY | O_CREAT, 0644);

        if(in_file < 0 || out_file < 0)
        {
            perror("Error in file handling");
            exit(EXIT_FAILURE);
        }

        //additional function which does the file searching under directories and return full path
        char* filename = argv[1];
        const char* filePath = dirSearch(filename);
        if(access(filePath, F_OK) < 0)
        {
            perror("File accessing error");
            exit(EXIT_FAILURE);
        }
        
        //forking for the first commnand
        int pid1 = fork();
        if(pid1 == 0)
        {
            dup2(in_file, STDIN_FILENO);
            dup2(fd[1], STDOUT_FILENO); //WR_END to STDOUT(1)
            close(fd[0]);
            close(fd[1]);
            close(in_file);
            exec_command(argv[2]);
        }
        waitpid(pid1, NULL, 0);
        //forking for the second commnand
        int pid2 = fork();
        if(pid2 == 0)
        {
            dup2(fd[0], STDIN_FILENO); //READ_END to STDOUT(0)
            dup2(out_file, STDOUT_FILENO); 
            close(fd[0]);
            close(fd[1]);
            close(out_file);
            exec_command(argv[3]);
        }
        waitpid(pid2, NULL, 0);
    }
    else 
    {
        printf("Usage format:");
    }

       
}


    
    //at the very end add waitpid(pid) to wait for pid to finish