#include "../include/map.h"

void draw_slider(t_map *map)
{
	draw_img(map, &(t_info){40, 120, 220, 100}, map->inter_tex[9]);
	if (map->block_tex[0]->active || map->block_tex[1]->active ||
	 map->block_tex[2]->active || map->block_tex[3]->active)
	{
		draw_img(map, &(t_info){70, 140, 25, 25}, map->inter_tex[11]);
		draw_img(map, &(t_info){195, 140, 25, 25}, map->inter_tex[10]);
		draw_line(map, 100, 95, 152);
		draw_line(map, 100, 95, 153);
		draw_line(map, 100, 95, 154);
		bigdot(map, 115 + (map->wclick), 153, RED);
		fonts_classic(map, "radius", 122, 132);
	}
}

void draw_line(t_map *map, int width, int x, int y)
{
	int i;

	i = -1;
	while (++i < width)
	{
		draw_pixel(map, x+i, y, (t_color){255,255,255});
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

