/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:26:35 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 14:10:34 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "vm.h"

void	winner(t_vm *vm, t_window *win)
{
	SDL_Rect	title_rec;
	SDL_Rect	winner_rec;
	char		*winner;
	int			w;
	int			h;

	winner = vm->all_players[vm->last_player_alive - 1]->name->str;
	w = win->w;
	h = win->h;
	title_rec = init_new_rect(w * 0.31, h * 0.40, w * 0.14, h * 0.05);
	winner_rec = init_new_rect(w * 0.33, h * 0.50, w * 0.1, h * 0.05);
	classic_writing(win, &title_rec, "The winner is :");
	classic_writing(win, &winner_rec, winner);
}
