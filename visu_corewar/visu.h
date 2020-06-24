/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:28:58 by francis           #+#    #+#             */
/*   Updated: 2020/06/20 20:13:44 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# define	SUCCESS			0
# define	FAILURE			-1
# define	RENDER_FAILURE	-2
# define	FONT_PATH "comfortaa/Comfortaa-Regular.ttf" 
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

typedef struct	s_window
{
	int				w;
	int				h;
	SDL_Window		*window;
	SDL_Surface		*background;
	SDL_Renderer	*renderer;
}				t_window;

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
int8_t		font_writing(t_window *win, SDL_Rect *rect, char *str, int size);
int8_t		green_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		blue_writing(t_window *win, SDL_Rect *rect, char *str);
int8_t		red_writing(t_window *win, SDL_Rect *rect, char *str);

/*
** ****************************** DRAWING **************************************
*/
int8_t		draw_zones(t_window *win);
void		draw_memory(t_window *win);
void		draw_header_box(t_window *win);
void		draw_players_box(t_window *win);
void		write_player_box(t_window *win, int x, int y);
void		write_info_box(t_window *win, int x, int y);
void		player1_input_writing(t_window *win, int x, int y);
void		player2_input_writing(t_window *win, int x, int y);
void		player3_input_writing(t_window *win, int x, int y);
void		player4_input_writing(t_window *win, int x, int y);

#endif