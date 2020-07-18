/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:52:38 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 11:38:52 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include "define_vm.h"

typedef struct		s_player
{
	t_vector		*name;
	t_vector		*comment;
	uint8_t			*exec;
	uint32_t		size;
	uint8_t			id;
	char			padding[3];
}					t_player;

/*
** id: unique.
** carry: flag changed by certain operations and which affects zjmp operation.
** opcode: operation code, before the battle starts it is not initialised.
** last_live: nb of cycle in which current cursor performed ope live last time.
** wait_cycles: amount of cycles to wait before operation execution.
** pc: address in memory
** jump: amount of bytes cursor must jump to get to the next operation
** registries[REG_NUMBER]: registries of current cursor
*/
typedef struct		s_cursor
{
	int32_t			registries[REG_NUMBER + 1];
	size_t			pc;
	size_t			wait_cycle;
	size_t			last_live;
	uint32_t		op_code;
	int32_t			param[3];
	uint8_t			carry;
	uint8_t			id;
	char			padding[5];
	struct s_cursor	*next;
}				t_cursor;

typedef struct		s_op_tab t_op_tab;

typedef struct		s_vm
{
	t_player		**all_players;
	uint8_t			arena[MEM_SIZE];
	t_cursor		*cursor;
	long			cycle_to_die;
	size_t			cycle_counter;
	size_t			live_counter;
	size_t			check_counter;
	size_t			opt_dump;
	uint8_t			option;
	uint8_t			last_player_alive;
	uint8_t			nb_of_player_alive;
}					t_vm;

/*
** op_tab functions
*/
typedef struct		s_op_tab
{
	char			*name;
	void			(*op_func)(t_vm *vm, t_cursor *cursor);
	uint8_t			nb_param;
	int32_t			type_param[3];
	uint8_t			op_code;
	size_t			wait_cycle;
	char			*comment;
	uint8_t			bytecode;
	uint8_t			dir_size;
}					t_op_tab;

extern t_op_tab		g_op_tab[17];

/*
** ############################################################################
** ################################# INIT #####################################
** ############################################################################
*/
t_vm		*init_and_parse(size_t ac, char **av);
ssize_t		get_nb(char *nb_str);
int8_t		check_file_name(char *file, size_t len);
int8_t		parse_file_and_get_info(t_vm *vm, t_vector *file, size_t index);
uint8_t		hexa(t_vector *file, size_t i);
t_vm		*malloc_vm_and_players(void);
int8_t		is_player_well_assigned(t_vm *vm);
t_vm		*set_up_arena(t_vm *vm);

/*
** ############################################################################
** ############################### BATTLE #####################################
** ############################################################################
*/
void		battle(t_vm *vm);
void		lets_fight(t_vm *vm, t_cursor *cursor);
void		move_to_next_op(t_vm *vm, t_cursor *cursor, uint8_t op_code);
uint8_t		get_param(t_vm *vm, t_cursor *cursor, size_t pc);
uint8_t		param_type(t_vm *vm, t_cursor *cursor, uint8_t bit_shift);
int32_t		get_register(t_cursor *cursor, size_t reg_number);
int32_t		get_indirect(t_vm *vm, t_cursor *cursor, uint8_t nb_arg);
int32_t		modulo(int32_t a, int32_t b);
int32_t		get_param_when_3_possible_type(t_vm *vm, t_cursor *cursor, 
									uint8_t arg, uint8_t type);

/*
** ############################################################################
** ############################## OPERATION ###################################
** ############################################################################
*/
uint8_t		check_bytecode_and_param(uint8_t op_code, uint8_t bytecode);
uint8_t		check_register(t_vm *vm, size_t pc, uint8_t bytecode);
void		op_live(t_vm *vm, t_cursor *cursor);
void		op_ld(t_vm *vm, t_cursor *cursor);
void		op_st(t_vm *vm, t_cursor *cursor);
void		op_add(t_vm *vm, t_cursor *cursor);
void		op_sub(t_vm *vm, t_cursor *cursor);
void		op_and(t_vm *vm, t_cursor *cursor);
void		op_or(t_vm *vm, t_cursor *cursor);
void		op_xor(t_vm *vm, t_cursor *cursor);
void		op_zjmp(t_vm *vm, t_cursor *cursor);
void		op_ldi(t_vm *vm, t_cursor *cursor);
void		op_sti(t_vm *vm, t_cursor *cursor);
void		op_lld(t_vm *vm, t_cursor *cursor);
void		op_lldi(t_vm *vm, t_cursor *cursor);
void		op_aff(t_vm *vm, t_cursor *cursor);
void		op_fork(t_vm *vm, t_cursor *cursor);
t_cursor	*fork_cursor(t_cursor *cursor, int32_t address);
void		op_lfork(t_vm *vm, t_cursor *cursor);

/*
** ############################################################################
** ################################ PRINT #####################################
** ############################################################################
*/
void		annonce_player(t_player **all_players);
void		and_the_winner_is(t_vm *vm);
void		print_all_player_and_option(t_vm *vm);
void		print_player(t_player *player);
void		print_cursor(t_cursor *cursor);
void		dump_option(t_vm *vm);

/*
** ############################################################################
** ################################ CLEAN #####################################
** ############################################################################
*/
void 		clean_vm(t_vm **vm);
void		clean_player(t_player **player);
void		clean_cursor(t_cursor **cursor);

#endif
