/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:28:58 by francis           #+#    #+#             */
/*   Updated: 2020/07/13 22:13:47 by francis          ###   ########.fr       */
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
# define	SUCCESS			0
# define	FAILURE			-1
# define	RENDER_FAILURE	-2
# define	FONT_PATH "../virtual_machine/visualizator/font/Font-Regular.ttf"

typedef struct	s_window
{
	int				w;
	int				h;
	uint8_t			play;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}				t_window;

/*
** ******************************** INIT ***************************************
*/
int			setup_window(t_vm *vm);

/*
** ******************************** TOOLS **************************************
*/

SDL_Rect	init_new_rect(int x, int y, int width, int height);
SDL_Point	set_point(int x, int y);
SDL_Color	set_color(int red, int green, int blue, int alpha);
int8_t		draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);

/*
** ****************************** WRITING **************************************
*/
int8_t		classic_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		green_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		blue_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		red_writing(t_window *win, SDL_Rect *rect, char *str);

/*
** ****************************** DRAWING **************************************
*/
int8_t		draw_zones(t_window *win);
void		draw_arena(t_window *win);
void		draw_header_rec(t_window *win);
void		draw_players_rec(t_window *win);
void		write_player_rec(t_window *win, int x, int y);
void		write_info_rec(t_window *win, int x, int y);
void		write_command_rec(t_window *win, int x, int y);
int8_t		write_init_arena(t_window *win);
void		player1_input_writing(t_window *win, int x, int y);
void		player2_input_writing(t_window *win, int x, int y);
void		player3_input_writing(t_window *win, int x, int y);
void		player4_input_writing(t_window *win, int x, int y);

#endif
