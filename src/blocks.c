#include "../include/map.h"

void drawline(t_map *map, int width, int x, int y)
{
	int i;

	i = -1;
	while (++i < width)
	{
		draw_pixel(map, x+i, y, (t_color){255,255,255});
	}
}

void draw_slider(t_map *map)
{
	draw_img(map, 9, 40, 120, 220, 100);
	draw_img(map, 11, 70, 140, 25, 25);
	draw_img(map, 10, 195, 140, 25, 25);
	drawline(map, 100, 95, 152);
	drawline(map, 100, 95, 153);
	drawline(map, 100, 95, 154);
	bigdot(map, 145 + map->wclick, 153, RED);
}

void hexagon(t_map *map, int x, int y)
{
	add_my_node(map, (x - 60) - map->wclick, (y - 90) - map->wclick, (x + 60) + map->wclick, (y - 90) - map->wclick); ///     ----
	add_my_node(map, (x - 90) - map->wclick, y, (x - 60) - map->wclick, (y - 90) - map->wclick); /// /
	add_my_node(map, (x - 90) - map->wclick, y , (x - 60) - map->wclick, (y + 90) + map->wclick); //  \         //
	add_my_node(map, (x + 90) + map->wclick, y, (x + 60) + map->wclick, (y - 90) - map->wclick); //            \ //
	add_my_node(map, (x + 90) + map->wclick, y, (x + 60) + map->wclick, (y + 90) + map->wclick); //            /
	add_my_node(map, (x - 60) - map->wclick, (y + 90) + map->wclick, (x + 60) + map->wclick, (y + 90) + map->wclick); /// 	----
}

void octagon(t_map *map, int x, int y)
{
	add_my_node(map, (x - 30) - map->wclick, (y - 50) - map->wclick, (x + 30) + map->wclick, (y - 50) - map->wclick); ///     ----
	add_my_node(map, (x - 50) - map->wclick, (y - 25) - map->wclick, (x - 30) - map->wclick, (y - 50) - map->wclick); ///     /
	add_my_node(map, (x - 50) - map->wclick, (y - 25) - map->wclick, (x - 50) - map->wclick, (y + 25) + map->wclick); ///     |
	add_my_node(map, (x - 50) - map->wclick, (y + 25) + map->wclick, (x - 30) - map->wclick, (y + 50) + map->wclick); ///     \ //

	add_my_node(map, (x - 30) - map->wclick, (y + 50) + map->wclick, (x + 30) + map->wclick, (y + 50) + map->wclick);//        ----
	add_my_node(map, (x + 30) + map->wclick, (y - 50) - map->wclick, (x + 50) + map->wclick, (y - 25) - map->wclick); ///     \ //
	add_my_node(map, (x + 50) + map->wclick, (y - 25) - map->wclick, (x + 50) + map->wclick, (y + 25) + map->wclick); ///     |
	add_my_node(map, (x + 50) + map->wclick, (y + 25) + map->wclick, (x + 30) + map->wclick, (y + 50) + map->wclick); ///     /


}

void pentagon(t_map *map, int x, int y)
{
	add_my_node(map, (x - 45) - map->wclick, (y - 25) - map->wclick, x, (y - 75) - map->wclick); ///     ----
	add_my_node(map, (x - 45) - map->wclick, (y - 25) - map->wclick, (x - 35) - map->wclick, (y + 25) + map->wclick); ///     ----
	add_my_node(map, (x - 35) - map->wclick, (y + 25) + map->wclick, (x + 35) + map->wclick, (y + 25) + map->wclick); ///     ----
	add_my_node(map, (x + 35) + map->wclick, (y + 25) + map->wclick, (x + 45) + map->wclick, (y - 25) - map->wclick); ///     ----
	add_my_node(map, (x + 45) + map->wclick, (y - 25) - map->wclick, x, (y - 75) - map->wclick); ///     ----

}

// void made_blocks(t_map *map)
// {
// 	add_my_node(map, 500 - map->tmp, 270 - map->tmp, 600 + map->tmp, 270 - map->tmp); ///     ----
// 	add_my_node(map, 470 - map->tmp, 350 , 500 - map->tmp, 270 - map->tmp); /// /
// 	add_my_node(map, 470 - map->tmp, 350, 500 - map->tmp, 430 + map->tmp); //  \         //
// 	add_my_node(map, 630 + map->tmp, 350, 600 + map->tmp, 270  - map->tmp); //            \ //
// 	add_my_node(map, 630  + map->tmp, 350, 600 + map->tmp, 430 + map->tmp); //            /
// 	add_my_node(map, 500 - map->tmp, 430 + map->tmp, 600 + map->tmp, 430  + map->tmp); /// 	----

// 	// find_remove(map, 500 - map->tmp, 270 - map->tmp);
// 	// find_remove(map, 630 + map->tmp, 350);
// }

void add_my_node(t_map *map, int x1, int y1, int x2, int y2)
{
	t_nod *n;
	t_nod *cur;

	n = n_cr(x1- map->z_x, y1 - map->z_y, x2 - map->z_x, y2 - map->z_y);
	if (map->nod == NULL)
	{
		map->nod = n;
		return;
	}
	else
	{
		cur = map->nod;
		while (cur->nxt)
		{
			cur = cur->nxt;
		}
		cur->nxt = n;
	}
}
