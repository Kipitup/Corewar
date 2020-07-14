/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:01:37 by efischer          #+#    #+#             */
/*   Updated: 2020/07/14 14:13:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>

# define NB_TOKEN			28

# define TOO_FEW_ARG		"Too few argument"
# define TOO_MUCH_ARG		"Too much arguments"
# define INVALID_FILE_NAME	"Invalid file name"
# define OPEN_FAILURE		"Cannot open file"
# define MALLOC_FAILURE		"Cannot allocate memory"
# define USAGE				"Usage: ./asm mychampion.s"
# define PARSE_ERROR		"Parse error"

enum	e_token
{
	T_NAME_CMD,
	T_COMMENT_CMD,
	T_LABEL_CHAR,
	T_DIRECT_CHAR,
	T_SEPARATOR_CHAR,
	T_LIVE,
	T_LD,
	T_ST,
	T_ADD,
	T_SUB,
	T_AND,
	T_OR,
	T_XOR,
	T_ZJMP,
	T_LDI,
	T_STI,
	T_FORK,
	T_LLD,
	T_LLDI,
	T_LFORK,
	T_AFF,
	T_STRING,
	T_LABEL,
	T_NB,
	T_REGISTER,
	T_START,
	T_END,
	T_COMMENT
};

typedef struct	s_token
{
	enum e_token	type;
	char			*value;
}				t_token;

int			usage_error(int ac);
int			check_file_name(const char *file_name);
t_vector	*get_file_content(const char *file_name);
void		lexer_parser(const char *input);
void		lexer(const char *input, t_list **token_lst);
void		get_word(const char *input, t_token *token, size_t *pos);
void		ft_lstaddend(t_list **alst, t_list *new);
void		exit_error(t_list **token_lst);

#endif
