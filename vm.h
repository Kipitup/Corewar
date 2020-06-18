/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:52:38 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/18 15:37:14 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

//# include "libft.h"
//# include "define_corewar.h"

enum	e_states
{
	E_ERROR = -1,
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
	size_t			size;
	uint8_t			id;
	i_dont_know		executable_code; // uint8_t * ou char * ?
	uint8_t			registers[16];
}				t_player;

typedef struct	s_vm
{
	t_player		all_player[MAX_PLAYERS];
	uint8_t			arena[MEM_SIZE];
	enum e_states	state;
	uint8_t			option;
	size_t			opt_dump;
}				t_vm;


#endif
