/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:56:38 by nsan              #+#    #+#             */
/*   Updated: 2024/09/28 17:56:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>
#include "libft/libft.h"


char* findPath(char* cmd, char** envp);
int split_join(char* cmd, char** envp);
void childProcess(int in_file, int out_file, int fd[2], char* argv[], char** envp);
void errorHandling(char* str);
char* retrievePaths(char** envp);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int execute(char** split_paths, char** envp, char** av);
void errorOut();


#endif