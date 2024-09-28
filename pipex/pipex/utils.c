/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:56:25 by nsan              #+#    #+#             */
/*   Updated: 2024/09/27 19:53:29 by nsan             ###   ########.fr       */
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

int execute(char** split_paths, char** envp, char** av)
{
    int i;
    int j;
    int cmd_found;
    int flag;
    cmd_found = 0;
    i = -1;
    flag = 0;
    
    while(split_paths[i++] != NULL)
    {   
        j = 0;
        char* path_joined = ft_strjoin(split_paths[i], "/");    // /bin/
        while(av[j] != NULL)
        {
            char* search_program = ft_strjoin(path_joined, av[j]);  // /bin/bin     if(cmd-->/bin/ls>
            //free(path_joined);
            //fprintf(stderr, "Vainpot is singing\n");
            if(access(search_program, X_OK) == 0)
            {
                //fprintf(stderr, "Vainpot is humming\n");
                cmd_found = 1; 
                execve(search_program, &av[0], envp); //something to tweak atound av[0]
                //fprintf(stderr, "Vainpot is dancing\n");
                flag = 1;
                break;
            }
            free(search_program);
            j++;
        }
        if(flag == 1)
            break;
    }
    if(!cmd_found)
        return (1);
    return (0);
}

int split_join(char* cmd, char** envp)
{    
    int count;
    char** av;
    int ret;
    int i;
    char c;
    i = 0;
    count = 0;

    while(cmd[i])
    {
        if(cmd[i] == '/')
        {
            c = '/';
            break;
        }
        else if(cmd[i] == ' '){
            c = ' ';
            break;
        }
        i++;
    }
    av = ft_split(cmd, c); //ls -l   (/bin/ls)
    // i = 0;
    // while (av[i] != NULL)
    // {
    //     fprintf(stderr, "%s\n", av[i]);
    //     i++;
    // }
    while(av[count] != NULL)
        count++;
    char* all_paths = retrievePaths(envp);
    char** split_paths = ft_split(all_paths, ':'); // /bin/
    ret = execute(split_paths, envp, av);
    return (ret);
}

//execve = {"/bin/ls", "ls", "-l", envp};