#include "../include/map.h"

void square(t_map *map, int x, int y)
{
	add_my_node(map, (x - 25) - map->wclick, (y - 25) - map->wclick, (x + 25) + map->wclick, (y - 25) - map->wclick);
	add_my_node(map, (x - 25) - map->wclick, (y - 25) - map->wclick, (x - 25) - map->wclick, (y + 25) + map->wclick);
	add_my_node(map, (x + 25) + map->wclick, (y - 25) - map->wclick, (x + 25) + map->wclick, (y + 25) + map->wclick);
	add_my_node(map, (x - 25) - map->wclick, (y + 25) + map->wclick, (x + 25) + map->wclick, (y + 25) + map->wclick);
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
