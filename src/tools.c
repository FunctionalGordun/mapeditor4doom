#include "../include/map.h"

int delete_node(t_nod *del, t_nod **first);

void	find_remove(t_map *map, int x, int y)
{
	t_nod *tmp;
	t_nod *first;

	tmp = map->nod;
	first = map->nod;
	while(tmp)
	{
		if (((tmp->x1 + map->z_x) == x && (tmp->y1 + map->z_y) == y) ||
		((tmp->x2 + map->z_x) == x && (tmp->y2 + map->z_y) == y))
		{
			tmp->removeflag = 1;
			//delete_node(tmp, &map->nod);
			printf("%d\n", delete_node(tmp, &first));
		}
		tmp = tmp->nxt;
	}
}

void	edit_tool(t_map *map, int index)
{
	int i;

	i = -1;
	edit_blocktexture(map, -1);
	while (++i < 9)
	{
		if (i == index)
			map->inter_tex[i]->active = 1;
		else
			map->inter_tex[i]->active = 0;
	}
}

void	edit_blocktexture(t_map *map, int index)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (i == index)
			map->block_tex[i]->active = 1;
		else
			map->block_tex[i]->active = 0;
	}
}

void	wall_editor(t_map *map, int x, int y)
{
	if (map->click == 0 && interface_click(map, x, y))
	{
		map->click = 1;
		map->x_c = x;
		map->y_c = y;
		find_coord(map, &(map->x_c), &(map->y_c));
	}
	else if (interface_click(map, x, y))
	{
		map->click = 0;
		find_coord(map, &x, &y);
		add_node(map, x, y);
		map->nod->index = nod_len(map->nod);
	}
}

int delete_node(t_nod *del, t_nod **first)
{
	t_nod *t = (*first)->nxt;
	t_nod *buf;
	if ( *first && *first != del ) { // Если список существует, и удоляемый элемент не является первым
		while ( t && t->nxt != del ) t = t->nxt; // Находим элемент, предшествубщий удоляемому
		if ( t ) { // Если он существует, то удаляем
			buf = t->nxt;
			t->nxt = t->nxt->nxt;
			free(buf);
			return 0; 
		}
		else
			return -1; // Иначе ошибка
	}
	else // Иначе
		if (*first != del) { // Если первый
			buf = del;
			*first = del->nxt;
			free(buf);
			return 0;
		}
		else // Если список пуст
			return -1;
}


void	remove_tool(t_map *map, int x, int y)
{
	int x1 = x;
	int y1 = y;

	find_coord(map, &x1, &y1);
	if (x1 != x || y1 != y)
		find_remove(map, x1, y1);
}