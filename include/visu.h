/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:28:58 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:46:39 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "vm.h"
# include "define_visu.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

typedef struct	s_window
{
	int				w;
	int				h;
	uint8_t			running;
	uint8_t			play;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	TTF_Font		*font;
	size_t			cycle_frame;
	size_t			nb_of_player;
}				t_window;

typedef struct	s_rectangle
{
	SDL_Rect	run_pause;
	SDL_Rect	to_die;
	SDL_Rect	cycle_frame;
	SDL_Rect	cycle_counter;
	SDL_Rect	name1;
	SDL_Rect	name2;
	SDL_Rect	name3;
	SDL_Rect	name4;
}				t_all_rec;

typedef struct	s_visu
{
	t_window	*win;
	t_all_rec	*all_rec;
}				t_visu;

typedef void	(*t_color_func)(t_window *win, SDL_Rect *rect, char *str);

/*
** ******************************* INIT ****************************************
*/
void			setup_window(t_vm *vm, t_window *win);
void			draw_init_zones(t_vm *vm, t_window *win, t_all_rec *all_rec);
void			init_arena(t_window *win);

/*
** ****************************** RUNNING **************************************
*/
void			active_zones(t_vm *vm, t_window *win, t_all_rec *all_rec);
void			ending_screen(t_vm *vm, t_window *win, t_all_rec *all_rec);
void			active_arena(t_vm *vm, t_window *win);
void			run_visu(t_vm *vm, t_window *win);
void			end_visu(t_vm *vm, t_window *win);
void			winner(t_vm *vm, t_window *win);
/*
** ******************************* CLEAN ***************************************
*/
void			destroy_visual(t_window *win);

/*
** ******************************* TOOLS ***************************************
*/
SDL_Rect		init_new_rect(int x, int y, int width, int height);
SDL_Point		set_point(int x, int y);
SDL_Color		set_color(int red, int green, int blue, int alpha);
void			event_handler(t_window *win);

/*
** ****************************** WRITING **************************************
*/
void			classic_writing(t_window *win, SDL_Rect *rect, char *str);
void			green_writing(t_window *win, SDL_Rect *rect, char *str);
void			blue_writing(t_window *win, SDL_Rect *rect, char *str);
void			red_writing(t_window *win, SDL_Rect *rect, char *str);
void			purple_writing(t_window *win, SDL_Rect *rect, char *str);

/*
** ****************************** DRAWING **************************************
*/
void			player_box(t_vm *vm, t_window *w, t_all_rec *rec, SDL_Point pt);
void			info_box(t_window *win, t_all_rec *rec, int x, int y);
void			command_box(t_window *win, t_all_rec *rec,int x, int y);
void			draw_arena(t_window *win);
void			draw_header_rec(t_window *win);
void			draw_player_info_comm_rec(t_vm *vm, t_window *w, t_all_rec *rc);
void			player1_input_writing(t_window *w, t_all_rec *rc, int x, int y);
void			player2_input_writing(t_window *w, t_all_rec *rc, int x, int y);
void			player3_input_writing(t_window *w, t_all_rec *rc, int x, int y);
void			player4_input_writing(t_window *w, t_all_rec *rc, int x, int y);

#endif
