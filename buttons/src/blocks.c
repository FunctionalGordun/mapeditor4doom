#include "../include/map.h"

void add_my_node(t_map *map, int x1, int y1, int x2, int y2);

void made_blocks(t_map *map)
{
	add_my_node(map, 500, 300, 600, 300);
	add_my_node(map, 500, 400, 600, 400);
	add_my_node(map, 450, 350, 650, 350);
}

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

void draw_my_node(t_map *map, int mx1, int my1, int mx2, int my2)
{
	int x1;
	int y1;
	int x2;
	int y2;

	int dx;
	int dy;
	int er;
	int de;

	int i;
	int j;

	int diry;
	int di;

	x1 = mx1 + map->z_x;
	x2 = mx2 + map->z_x;
	if (x1 < 0 && x2 < 0)
		return;
	y1 = my1 + map->z_y;
	y2 = my2 + map->z_y;
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	er = 0;
	de = dy + 1;
	j = y1;
	i = x1;
	di = 0;
	
	if (dx > dy)
	{
		i = x1;
		j = y1;
		di = (x2 - x1) / dx;
		diry = y2 - y1;
		de = dy + 1;
		if (diry > 0)
			diry = 1;
		if (diry < 0)
			diry = -1;
		
		while (i != x2)
		{
			draw_gr(map, i, j, GREEN);
			er += de;
			if (er >= dx + 1)
			{
				j += diry;
				er = er - (dx + 1);
			}
			i += di;
		}
	}
	else if (dy != 0)
	{
		i = y1;
		j = x1;
		di = (y2 - y1) / dy;
		diry = x2 - x1;
		de = dx + 1;
		if (diry > 0)
			diry = 1;
		if (diry < 0)
			diry = -1;
		
		while (i != y2)
		{
			draw_gr(map, j, i, GREEN);
			er += de;
			if (er >= dy + 1)
			{
				j += diry;
				er = er - (dy + 1);
			}
			i += di;
		}
	}
	bigdot(map, x1, y1, RED);
	bigdot(map, x2, y2, RED);
}