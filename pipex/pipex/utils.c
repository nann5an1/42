/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 20:01:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"
void errorHandling(char* str)
{
    perror(str);
    exit(EXIT_FAILURE);
}

char* retrievePaths(char** envp)
{

    int i = 0;
    while(envp[i] != NULL)
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    errorHandling("File not found");
    return (NULL);
}

int exec_command(char* cmd, char** envp)
{    
    int i;
    int cmd_found;
    cmd_found = 0;
    i = -1;
   
    if(cmd[0] == '/')
    {
        // fprintf(stderr, "Vainpot NOT in exec_command split/ join\n");
        char** argv = malloc(sizeof(char*) * 2);
        argv[1] = NULL;
        argv[0] = cmd;
        if(access(cmd, X_OK) == 0)
        {
            // fprintf(stderr, "Vainpot is singing\n");
            execve(cmd, argv, envp);
            // fprintf(stderr, "Vainpot after singing\n");
        }
        else
            ft_putstr_fd("No such file or directory\n", 2);
    }
    else
    {
        // fprintf(stderr, "Vainpot in exec_command split/ join\n");
        char** av = ft_split(cmd, ' '); //ls -l or // /bin/ls
        char* all_paths = retrievePaths(envp);
        char** split_paths = ft_split(all_paths, ':');
        // fprintf(stderr, "Vainpot in exec_command after split_path\n");
        cmd_found = 0;
        while(split_paths[i++] != NULL)
        {
            char* path_joined = ft_strjoin(split_paths[i], "/");    
            char* search_program = ft_strjoin(path_joined, av[0]);
            if(access(search_program, X_OK) == 0)
            {
                // fprintf(stderr, "Vainpot in exec_command in execve\n");
                cmd_found = 1;
                execve(search_program, &av[0], envp);
                // fprintf(stderr, "Vainpot in exec_command after execve\n");
                break;
            }
            free(path_joined);
            free(search_program);
        }
        if(!cmd_found)
            return (1);
        //fprintf(stderr, "Vainpot in exec_command after while\n");
    }
    return (0);
    // fprintf(stderr, "Vainpot done executing\n");
}

//execve = {"/bin/ls", ("ls", "-l", NULL), envp};
//execve = {"/bin/ls", (NULL), envp};
        //if the command is not found, print an error message

//handling /dev/urandom
//error output handling
          //  ft_putstr_fd("Error: command not found\n", 1);
