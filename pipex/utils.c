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
void errorHandling(char* str)
{
    perror(str);
    exit(EXIT_FAILURE);
}

char** retrievePaths(char** envp)
{

    int i = 0;
    while(envp[i] != '\0')
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        else
            errorHandling("File not found");
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
            errorHandling("File path not found");
        free(search_program);
    }
}