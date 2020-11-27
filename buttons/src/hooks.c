#include "../include/map.h"

int interface_click(t_map *map, int x, int y)
{
	if ((x > 0 &&  x < 300) && y > 0 && y < 800)
		return(0);
	return(1);
}

void section_click(t_map *map, int x, int y)
{
	if ((x > 80 &&  x < 80 + map->inter_tex[6]->img->w) && y > 60 && y < 60 + map->inter_tex[6]->img->h)
		edit_tool(map, 6);
	if ((x > 130 &&  x < 130 + map->inter_tex[7]->img->w) && y > 60 && y < 60 + map->inter_tex[7]->img->h)
		edit_tool(map, 7);
	if ((x > 180 &&  x < 180 + map->inter_tex[8]->img->w) && y > 60 && y < 60 + map->inter_tex[8]->img->h)
		edit_tool(map, 8);
}