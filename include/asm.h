/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:01:37 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 19:01:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>

# define NB_OP				16
# define NB_TOKEN			28
# define NB_STATE			3

# define TOO_FEW_ARG		"Too few argument"
# define TOO_MUCH_ARG		"Too much arguments"
# define INVALID_FILE_NAME	"Invalid file name"
# define OPEN_FAILURE		"Cannot open file"
# define MALLOC_FAILURE		"Cannot allocate memory"
# define USAGE				"Usage: ./asm mychampion.s"
# define PARSE_ERROR		"Parse error"
# define TOO_LONG_NAME		"Program name too long"
# define WRONG_LABEL_NAME	"Invalid label name"
# define INVALID_ARG		"Invalid argument"
# define UNDEFINED_LABEL	"Undefined label"
# define NO_INSTRUCTION		"No instruction"
# define NO_ARG				"Instruction without any argument"
# define WRONG_REG_NB		"Invalid register number"

# define REGISTER_SIZE		1
# define SMALL_DIRECT_SIZE	2
# define LONG_DIRECT_SIZE	4
# define INDIRECT_SIZE		2

enum			e_token
{
	E_LIVE,
	E_LD,
	E_ST,
	E_ADD,
	E_SUB,
	E_AND,
	E_OR,
	E_XOR,
	E_ZJMP,
	E_LDI,
	E_STI,
	E_FORK,
	E_LLD,
	E_LLDI,
	E_LFORK,
	E_AFF,
	E_NAME_CMD,
	E_COMMENT_CMD,
	E_LABEL_CHAR,
	E_DIRECT_CHAR,
	E_SEPARATOR_CHAR,
	E_STRING,
	E_OCP,
	E_REG,
	E_DIR,
	E_IND,
	E_LABEL,
	E_COMMENT
};

enum			e_state
{
	E_GET_NAME,
	E_GET_COMMENT,
	E_GET_OP
};

typedef struct	s_token
{
	enum e_token	type;
	char			*value;
	size_t			size;
	size_t			cur_offset;
}				t_token;

typedef struct	s_label
{
	char	*name;
	size_t	offset;
}				t_label;

typedef struct	s_data
{
	char			*input;
	t_list			*label_lst;
	t_list			*token_lst;
	char			*file_name;
	char			*cor_name;
	int				column;
	int				line;
	size_t			offset;
	ssize_t			fd_s;
	ssize_t			fd_cor;
	enum e_state	state;
}				t_data;

void			check_no_ocp_op(t_data *data, const enum e_token type,
						const uint64_t ocp);
void			check_op(t_data *data, const t_token *op_token,
						const t_token *ocp_token, const size_t nb_args);
void			check_op_args(t_data *data, t_token *op_token, uint64_t ocp,
						size_t nb_args);
bool			check_label_char(const char *arg);
void			del_array(char **array);
void			del_label_lst(void *content, size_t content_size);
void			del_token_lst(void *content, size_t content_size);
void			exit_error(t_data *data, char *err_mesage);
void			exit_routine(t_data *data);
void			fill_cor(t_data *data);
void			ft_arrdel(char **array);
void			ft_lstaddend(t_list **alst, t_list *new);
int				ft_isblank(const char c);
char			*ft_join_free(char *s1, char *s2, int op);
char			**ft_split_white_spaces(char const *s);
void			get_args(t_data *data, char *merge);
void			get_comment(t_data *data);
uint64_t		get_dir_arg(t_data *data, char *arg, const enum e_token type);
char			*get_dquote_string(t_data *data);
void			get_file_content(t_data *data);
uint64_t		get_ind_arg(t_data *data, char *arg);
void			get_instruction(t_data *data);
bool			get_label(t_data *data, char **split, size_t *index);
void			get_name(t_data *data);
uint64_t		get_next_arg(t_data *data, char *arg, const enum e_token type);
void			get_op(t_data *data, char **split, size_t *i);
uint64_t		get_reg_arg(t_data *data, char *arg);
bool			is_number(char *s);
void			new_token(t_data *data, enum e_token type, char *value,
						size_t size);
void			open_cor(t_data *data);
void			open_file(t_data *data);
void			parser_asm(t_data *data);
void			replace_label_offset(t_data *data);
char			*trim_side(char *s);
int				usage_error(int ac);

void			debug_label(t_list *label_lst);
void			debug_token(t_list *token_lst);

#endif
