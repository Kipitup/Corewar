/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:28:58 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 14:59:46 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "vm.h"
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# define	ON				1
# define	OFF				0
# define	VISU_START		1	
# define	VISU_STOP		0	
# define	SUCCESS			0
# define	FAILURE			-1
# define	RENDER_FAILURE	-2
# define	FONT_PATH "../virtual_machine/visualizator/font/Font-Regular.ttf"

typedef struct	s_window
{
	int				w;
	int				h;
	uint8_t			running;
	uint8_t			play;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}				t_window;

typedef struct	s_rectangle
{
	SDL_Rect	run_pause;	
	SDL_Rect	to_die;	
//	SDL_Rect	delta;
//	SDL_Rect	nb_live;
//	SDL_Rect	check;
	SDL_Rect	name1;
	SDL_Rect	player1_process;
	SDL_Rect	player1_live;
	SDL_Rect	name2;
	SDL_Rect	player2_process;
	SDL_Rect	player2_live;
	SDL_Rect	name3;
	SDL_Rect	player3_process;
	SDL_Rect	player3_live;
	SDL_Rect	name4;
	SDL_Rect	player4_process;
	SDL_Rect	player4_live;
}				t_all_rec;

typedef struct	s_visu
{
	t_window	*win;
	t_all_rec	*all_rec;
}				t_visu;

int8_t		(*color_func)(t_window *win, SDL_Rect *rect, char *str);

/*
** ******************************* INIT ****************************************
*/
void		setup_window(t_vm *vm, t_window *win);
void		draw_init_zones(t_vm *vm, t_window *win, t_all_rec *all_rec);
void		init_arena(t_window *win);

/*
** ****************************** RUNNING **************************************
*/
void		active_zones(t_vm *vm, t_window *win, t_all_rec *all_rec);
void		active_arena(t_vm *vm, t_window *win);
int			run_visu(t_vm *vm, t_window *win);
/*
** ******************************* CLEAN ***************************************
*/
void		destroy_visual(t_window *win);

/*
** ******************************* TOOLS ***************************************
*/
SDL_Rect	init_new_rect(int x, int y, int width, int height);
SDL_Point	set_point(int x, int y);
SDL_Color	set_color(int red, int green, int blue, int alpha);
int8_t		draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);
void		event_handler(t_window *win);

/*
** ****************************** WRITING **************************************
*/
int8_t		classic_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		green_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		blue_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		red_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		purple_writing(t_window *win, SDL_Rect *rect, char *str);

/*
** ****************************** DRAWING **************************************
*/
void		player_box(t_vm *vm, t_window *win, t_all_rec *rec, int x, int y);
void		info_box(t_window *win, t_all_rec *rec, int x, int y);
void		command_box(t_window *win, t_all_rec *rec,int x, int y);
void		draw_arena(t_window *win);
void		draw_header_rec(t_window *win);
void		draw_player_info_comm_rec(t_vm *vm, t_window *win, t_all_rec *rec);

void		player1_input_writing(t_window *win, t_all_rec *rec, int x, int y);
void		player2_input_writing(t_window *win, t_all_rec *rec, int x, int y);
void		player3_input_writing(t_window *win, t_all_rec *rec, int x, int y);
void		player4_input_writing(t_window *win, t_all_rec *rec, int x, int y);

#endif
