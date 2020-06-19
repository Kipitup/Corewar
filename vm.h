/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:52:38 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/19 18:27:35 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

//# include "libft.h"
//# include "define_corewar.h"

enum	e_states
{
	E_ERROR = FAILLURE,
	E_PARSE = 0,
	E_OPTION = 1,
	E_PLAYER = 2,
	E_END = 3
};

typedef struct	s_player
{
	t_vector		*file;
	t_vector		*name;
	t_vector		*comment;
	uint8_t			*exe;
	size_t			size;
	uint8_t			id;
	char			padding[7];
}				t_player;

typedef struct	s_carriage
{
	uint8_t				registers[REG_NUMBER][REG_SIZE];
	size_t				current;
	size_t				go_to_next_ope;
	size_t				nb_cycle_before_op;
	size_t				last_live;
	uint8_t				op_code;
	uint8_t				carry;
	uint8_t				id;
	char				padding[5];
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_vm
{
	t_player		all_player[MAX_PLAYERS];
	uint8_t			arena[MEM_SIZE];
	enum e_states	state;
	t_carriage		*carriage;
	size_t			cycles_to_die;
	size_t			nb_total_cycle;
	size_t			nb_total_live;
	size_t			nb_total_check;
	size_t			opt_dump;
	uint8_t			option;
	uint8_t			last_player_alive;
}				t_vm;


# define OPT_DUMP	0b00000001
# define OPT_VISU	0b00000010


#endif
