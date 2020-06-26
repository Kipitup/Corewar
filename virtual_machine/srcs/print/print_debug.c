/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:14:01 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/26 17:58:17 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_player(t_player *player)
{
	size_t		i;

	i = 0;
	if (player != NULL)
	{
		ft_dprintf(STD_ERR, "{c_magenta}.name:    {c_end}%s\n",
				player->name->str);
		ft_dprintf(STD_ERR, "{c_magenta}.comment: {c_end}%s\n{c_yellow}",
				player->comment->str);
		while (i < player->size)
		{
			if (i % 16 == 0 && i != 0)
				ft_dprintf(STD_ERR, "\n");
			else if (i % 8 == 0 && i != 0)
				ft_dprintf(STD_ERR, " ");
			ft_dprintf(STD_ERR, "%02b ", 16, player->exec[i]);
			i++;
		}
		ft_dprintf(STD_ERR, "{c_end}\n");
	}
}

void		print_all_player_and_option(t_vm *vm)
{
	size_t		i;

	i = 0;
	if (vm != NULL)
	{
		ft_printf("option: %08b\n",  2, vm->option);
		ft_printf("dump nb %zu\n\n", vm->opt_dump);
		while (i < MAX_PLAYERS)
		{
			if (vm->all_players[i] != NULL)
			{
				ft_dprintf(STD_ERR, "- - - - - - - - - - - - - - - - - - - - -\
 - - - - \n");
				ft_dprintf(STD_ERR, "{c_cyan}Player number %zu{c_end}\n",
						vm->all_players[i]->id);
				print_player(vm->all_players[i]);
				ft_dprintf(STD_ERR, "\n");
			}
			i++;
		}
	}
}

void		print_cursor(t_cursor *cursor)
{
	size_t		i;

	while (cursor != NULL)
	{
		i = 1;
		ft_dprintf(STD_ERR, "{c_cyan}Cursor ID: %d{c_end}\n", cursor->id);
		ft_dprintf(STD_ERR, "Current  : {c_green}%zu{c_end}\n", cursor->current);
		ft_dprintf(STD_ERR, "Registers: | r1   | r2   | r3   | r4   | r5   |\
 r6   | r7   | r8   | r9   | r10  | r11  | r12  | r13  | r14  | r15  | r16  |\
 \n\t   {c_yellow}");
		while (i <= REG_NUMBER)
		{
			ft_dprintf(STD_ERR, "| %-4d ", cursor->registers[i]);
			i++;
		}
		ft_dprintf(STD_ERR, "|{c_end}\n");
		if (cursor->next != NULL)
			ft_dprintf(STD_ERR, "\t\t\t\t\t{c_red}||\n\t\t\t\t\t\\/{c_end}\n");
		cursor = cursor->next;
	}
}

void		dump_option(t_vm *vm)
{
	size_t		i;
	size_t		dump_type;

	i = 0;
	if (vm != NULL)
	{
		dump_type = (vm->option & OPT_DUMP32) ? 32 : 64;
		while (i < MEM_SIZE)
		{
			if (i % dump_type == 0)
				ft_dprintf(STD_ERR, "\n 0x%04X : ", i);
			else if (i % 8 == 0 && i != 0)
				ft_dprintf(STD_ERR, " ");
			ft_dprintf(STD_ERR, "%02b ", 16, vm->arena[i]);
			i++;
		}
		ft_dprintf(STD_ERR, "{c_end}\n");
	}
}



