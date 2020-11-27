#include "../include/map.h"

void draw_img(t_map *map, int inx, int x, int y, int wdth, int hth)
{
	int i;
	int j;
	int pixel1;
	int pixel2;

	i = y;
	while (i < HEIGHT && i < y + hth)
	{
		j = x;
		while (j < WIDTH && j < x + wdth)
		{
			pixel1 = i * map->inter_tex[0]->strb + j * map->inter_tex[0]->pixb;
			pixel2 = (int)((double)(i-y)/hth * map->inter_tex[inx]->img->h) * map->inter_tex[inx]->strb + (int)((double)(j - x)/wdth * map->inter_tex[inx]->img->w) * map->inter_tex[inx]->pixb;
			map->inter_tex[0]->s[pixel1] = map->inter_tex[inx]->s[pixel2];
			map->inter_tex[0]->s[++pixel1] = map->inter_tex[inx]->s[++pixel2];
			map->inter_tex[0]->s[++pixel1] = map->inter_tex[inx]->s[++pixel2];
			j++;
		}
		i++;
	}
}

void	draw_color(t_map *map, int pixel, t_color color)
{
	map->inter_tex[0]->s[pixel] = color.b;
	map->inter_tex[0]->s[++pixel] = color.g;
	map->inter_tex[0]->s[++pixel] = color.r;
}


void draw_pixel(t_map *map, int x, int y, t_color color)
{
	int pixel;

	if (x < WIDTH && y < HEIGHT)
	{
		pixel = (x * map->inter_tex[0]->pixb) + (y * map->inter_tex[0]->strb);
		draw_color(map, pixel, color);
	}
}

void draw_point(t_map *map, int x, int y, t_color color)
{
	int i;
	int j;
	int pixel;

	i = -1;
	while (i < 1)
	{
		j = -1;
		while (j < 1)
		{
			if (x + i >= 0 && y + j >= 0 && x + i < WIDTH && y + j < HEIGHT)
			{
				pixel = ((x + i) * map->inter_tex[0]->pixb) + ((y + j) * map->inter_tex[0]->strb);
				draw_color(map, pixel, color);
			}
			j++;
		}
		i++;
	}
}


void bigdot(t_map *map, int x, int y, t_color color)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			draw_point(map, x + i, y + j, color);
			j++;
		}
		i++;
	}
}


void draw_grid(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if ((i - map->z_y) % SCALE == 0 && (j - map->z_x) % SCALE == 0)
				draw_point(map, j, i, GREY);
			else if ((i - map->z_y) % SCALE == 0 || (j - map->z_x) % SCALE == 0)
				
				draw_pixel(map, j, i, APPLEGREY);
			else
				draw_pixel(map, j, i, (t_color){0, 0, 0});
			j++;
		}
	}
}


void draw(t_map *map)
{
	SDL_FillRect(map->inter_tex[0]->img, NULL, 0);
	draw_grid(map);
	draw_img(map, 1, 0, 0, 300, 800);
	draw_img(map, 2, 10, 110, 280, 680);

	draw_img(map, 3, 20, 20, 70, 30);
	draw_img(map, 4, 110, 20, 70, 30);
	draw_img(map, 5, 200, 20, 70, 30);

	draw_img(map, 6, 80, 60, 30, 30);
	draw_img(map, 7, 130, 60, 30, 30);
	draw_img(map, 8, 180, 60, 30, 30);

	if (map->click)
		bigdot(map, map->x_c, map->y_c, RED);
	draw_nodes(map);
	SDL_UpdateWindowSurface(map->win);
}