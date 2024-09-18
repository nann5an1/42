/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 13:07:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void errorHandling(int options)
{
    if(options == 0)
        perror("Format Error");
    else if(options == 1)
    {
        perror("Piping failed");
        exit(EXIT_FAILURE);
    }
    else if(options == 2)
    {
        perror("File is not accessible");
        exit(EXIT_FAILURE);
    }
    else if(options == 3)
    {
        perror("File is not readable");
        exit(EXIT_FAILURE);
    }
    else if(options == 4)
    {
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }
}

char** retrievePaths(char** envp)
{

    int i = 0;
    while(envp[i] != '\0')
    {
         if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    return (NULL);
}

void exec_command(char* cmd, char** envp)
{    
    int i = -1;
    char* av[] = ft_split(cmd, " ");
    char* all_paths = retrievePaths(envp);
    char** split_paths = ft_split(all_paths, ':');
    while(*split_paths[++i] != '\0')
    {
        char* path_joined = ft_strjoin(split_paths[i], '/');
        char* search_program = ft_strjoin(path_joined, av[0]);
        free(path_joined);
        if(access(search_program, R_OK | X_OK) == 0)
            execve(search_program, av, envp);
        else
            errorHandling("Path could not be executed");
        free(search_program);
    }
}