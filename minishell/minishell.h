/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:05 by nsan              #+#    #+#             */
/*   Updated: 2024/12/22 12:57:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include "libft/libft.h"

typedef enum e_token_types
{
	T_WORD = 0, //ls -l
	T_PIPE = 1, // |
	T_REDIRECT_IN = 2, // <
	T_REDIRECT_OUT = 3, // >
	T_APPEND = 4, // >>
	T_HERE_DOCS = 5, //<<
	T_VAR = 6, //$
} t_token_types;

typedef struct s_tokens
{
	char *str;
	t_token_types tok_types;
	struct s_tokens *next;
} t_tokens;

void detect_str(char *str, t_tokens tokens);
t_tokens *create_new_token(char *str);
void	ft_lstadd_back(t_tokens **lst, t_tokens *new);
void tokenize_str(t_tokens *new_token, char *str);
t_tokens **tokenization(char **dest, int count);
void execute_builtins(t_tokens **whole_list);
void execute_echo(t_tokens **whole_list);

#endif