/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:22:07 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 19:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include "libft/libft.h"

char* findPath(char* cmd, char** envp);
int exec_command(char* cmd, char** envp);
void errorHandling(char* str);
char* retrievePaths(char** envp);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);


#endif