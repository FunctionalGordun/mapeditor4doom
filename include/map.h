#ifndef MAP_H
# define MAP_H

#include "../SDL2/include/SDL2/SDL.h"
#include "../SDL2/include/SDL2/SDL_image.h"
#include "../SDL2/include/SDL2/SDL_ttf.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

# define APPLEGREY (t_color){33, 33, 33}
# define GREY (t_color){74, 74, 74}
# define WHITE (t_color){255, 255, 255}
# define RED (t_color){255, 0, 0}
# define GREEN (t_color){0, 255, 0}
# define YELLOW (t_color){255, 255, 0}
# define HOTPINK (t_color){255, 105, 180}

# define REDFONT (SDL_Color){255, 0, 0}


# define WIDTH 1224
# define HEIGHT 820
# define SCALE 30

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct			s_nod
{
	short				x1;
	short				y1;
	short				x2;
	short				y2;
	int					index;
	int					removeflag;
	struct s_nod		*nxt;
}						t_nod;

typedef struct	s_win
{
	int			xpos;
	int			ypos;
	int			h;
	int			w;
}				t_win;


typedef struct	s_image
{
	SDL_Surface			*img;
	unsigned char		*s;
	unsigned char		pixb;
	int					strb;
	int					active;
}					t_image;

typedef struct	s_info
{
	int x;
	int y;
	int w;
	int h;
}				t_info;

typedef struct	s_removeinfo
{
	int *x;
	int *y;
}				t_removeinfo;


typedef struct	s_map
{
	SDL_Window			*win;
	t_image				*inter_tex[25]; // 0 - window, 1-5 - inblock & (block, texture, object), 6-8 - tools 9-11 widget panel & widgets
	t_image				*block_tex[4]; // структура текстур раздела блоки
	t_image				*wall_tex[20];
	t_image				*floorsky_tex[13];
	t_image				*liquid_tex[4];
	t_image				*curosr_img;// структура изобр курсора
	t_image				*font; // шрифт
	SDL_Cursor			*cursor;// крусор
	t_nod				*nod; // все узлы на карте
	t_removeinfo		*remove; // tmp труктура для функции удаления готовых блоков

	int					wclick; // коэф + - виджета размера
	int					z_x; // половина окна по x
	int					z_y; // половина окна по y
	int					click; // клик первый раз
	int					tmpclick; // клик для фигур
	int					x_c; // x первого клика
	int					y_c; // y первого клика
	int					showactive; // флаг активности панели 1- walls 2 flor & sky 3 - liquids
	

	int 				change_x;
	int 				change_y;
	int 				change_plus;
	id_t				index_tex;
	// int 				change_minus;
}				t_map;



int		init_all(t_map *map);
void	init_interface(t_map *map);
void	init_texture(SDL_Surface *tex, unsigned char **s, unsigned char *pixb, int *strb);
void	get_inter_textures(t_map *map);
void	get_block_textures(t_map *map);
void	get_liquid_textures(t_map *map);
void	get_wall_textures(t_map *map);
void	get_floorsky_textures(t_map *map);


void	malloc_block_texture(t_map *map);
void	malloc_interface(t_map *map);
void	malloc_floorsky_texture(t_map *map);
void	malloc_wall_texture(t_map *map);
void	malloc_liquid_texture(t_map *map);
void	malloc_wall_texture(t_map *map);


void	draw(t_map *map);
void	draw_color(t_map *map, int pixel, t_color color);
void	draw_pixel(t_map *map, int x, int y, t_color color);
void	draw_point(t_map *map, int x, int y, t_color color);
void	draw_grid(t_map *map);
void	draw_img(t_map *map, t_info *info, t_image *st);
void	draw_nodes(t_map *map);
void draw_node(t_map *map, t_nod *n);
void	add_node(t_map *mp, int x, int y);
void	draw_gr(t_map *map, int x, int y, t_color color);
void	draw_line(t_map *map, t_info *info, t_color color);
void	draw_slider(t_map *map);
void	draw_block_textures(t_map *map);
void	draw_wall_textures(t_map *map);
void	draw_floorsky_textures(t_map *map);
void	draw_liquid_textures(t_map *map);


void	bigdot(t_map *map, int x, int y, t_color color);
t_nod	*n_cr(short x1, short y1, short x2, short y2);
void	find_coord(t_map *mp, int *x, int *y);
int		sq(int x1, int y1, int x2, int y2);
int		nod_len(t_nod *nod);
void	whichone_tool(t_map *map);


int	events(t_map *map);
int		mmove(int x, int y, t_map *map, SDL_Event event);
int		ukey(int key, t_map *map);
int		pkey(int key, t_map *map);
int		mkey(int key, int x, int y, t_map *map);


void	edit_tool(t_map *map, int index);
void	edit_blocktexture(t_map *map, int index);
void	wall_editor(t_map *map, int x, int y);
void	remove_tool(t_map *map, int x, int y);
void	find_remove(t_map *map, int x, int y);
void	remove_blocks(t_map *map);


int		interface_click(t_map *map, int x, int y);
void	section_click(t_map *map, int x, int y);
int		catch_click(t_map *map, int x, int y);
int		widget_click(t_map *map, int x, int y);
void	tools_click(t_map *map, int x, int y);
void	blockterxture_click(t_map *map, int x, int y);


void	add_my_node(t_map *map, int x1, int y1, int x2, int y2);
void	made_blocks(t_map *map, int x, int y);

void	square(t_map *map, int x, int y);
void	pentagon(t_map *map, int x, int y);
void	hexagon(t_map *map, int x, int y);
void	octagon(t_map *map, int x, int y);


void	cursor(t_map *map, const char *file, int hot_x, int hot_y);
void	fonts(t_map *map, char *str, int x, int y);
void	fonts_classic(t_map *map, char *str, int x, int y);
void fonts_doom(t_map *map, char *str, int x, int y, SDL_Color color);
int		struppercase(char *str);




void draw_showuppanel(t_map *map, int x, int y, int inx);
void	texture_block(t_map *map);
void	change_texture(t_map *map, int x, int y);

void open_texture_win(t_map *map);
void draw_changer_texture(t_map *map);

#endif
