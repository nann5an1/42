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

void exec_command()
{

}


//user compilation --> ./pipex.exe "in_file" "ls -l" "grep hello" "out_file"
int main(int argc, char** argv)
{
    int fd[2];
    pid_t pid1;
    int in_file;
    int out_file;
    if(argc == 5)
    {
        //creation of pipe
        if(pipe(fd) < 0){
            perror("Error in creating pipe");
            exit(EXIT_FAILURE);
        }

        in_file = open(argv[1], O_RDONLY);
        out_file = open(argv[4], O_WRONLY | O_CREAT, 0644);

        if(in_file < 0 || out_file < 0)
        {
            perror("Error in file handling");
            exit(EXIT_FAILURE);
        }
        exec_command(argv[2]);
        exec_command(argv[3]);

        //create child and parent process using fork for the first command
        int res;
        pid1 = fork();
        if(pid1 < 0)
        {
            perror("Error in creating child");
            exit(EXIT_FAILURE);
        }
             
        else if(pid1 == 0)
        {
            printf("Child process created");
            //additional function which does the file searching under directories and return full path
            char* filename = argv[1];
            const char* filePath = dirSearch(filename);
            res = access(filePath, F_OK);
            if(res < 0)
            {
                perror("File accessing error");
                exit(EXIT_FAILURE);
            }
            //file accessing is okay (permissions are allowed)
            char *const av[] = ft_split(argv[2]);
            const char* programDir = programSearch(av[0]);
            const char* envp[] = {NULL}; //path to the program i want to execute
                
            //redirectiong ouput to the pipe
            dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);

            if(execve(programDir, av, envp) < 0)
                perror("Error Executing");
        }
        else
        {
            printf("Parent process created");
            close(fd[1]);
            waitpid(pid1, NULL, 0);
        }         
    }
}
    

    //create child and parent process using fork for the second command
    
    //at the very end add waitpid(pid1) to wait for pid1 to finish