#include "../include/map.h"

void	edit_tool(t_map *map, int index)
{
	int i;

	i = 5;
	while (++i < 9)
	{
		if (i == index)
			map->inter_tex[i]->active = 1;
		else
			map->inter_tex[i]->active = 0;
	}
}

void	wall_editor(t_map *map, int x, int y)
{
	int x1;
	int y1;

	if (map->click == 0 && interface_click(map, x, y))
	{
		map->x_clck = x;
		map->y_clck = y;
		map->click = 1;
		map->x_c = (x - map->z_x);
		map->y_c = (y - map->z_y);
		if (map->sh == 0) //
			find_coord(map, &(map->x_c), &(map->y_c));
		// add_node(map, x, y);
	}
	else if (interface_click(map, x, y))
	{
		map->click = 0;
		x1 = (x - map->z_x);//
		y1 = (y - map->z_y);//
		if (map->sh == 0)//
			find_coord(map, &x1, &y1);
		add_node(map, x, y);
		map->nod->index = nod_len(map->nod);
		//printf("nod x %d y %d x2 %d y2 %d\n", map->nod->x1, map->nod->y1, map->nod->x2, map->nod->y2);
	}
	// map->nod->index = 
}