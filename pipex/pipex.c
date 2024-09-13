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
int main()
{
    int fd[2];
    pid_t pid1;

    //create a pipe
    if(pipe(fd) < 0)
        perror("Error in creating pipe");
    
    else if(pipe(fd) == 0)
    {
        printf("Pipe success");
    }

    //create child and parent process using fork for the first command
    pid1 = fork();
    if(pid1 < 0)
        perror("Error in creating child");
    else if(pid1 == 0)
    {
        //using of access() function
        printf("Child process created");
        //usage of dup()
        //close the un-necessary ends of pipes (even for the duplicated ones)
        // execve(); //execute the 
    }
    else
        printf("Parent process created");


    //create child and parent process using fork for the second command
    //at the very end add waitpid(pid1) to wait for pid1 to finish
    

}