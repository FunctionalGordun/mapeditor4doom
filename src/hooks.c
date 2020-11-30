#include "../include/map.h"

int interface_click(t_map *map, int x, int y)
{
	if ((x > 0 &&  x < 300) && y > 0 && y < 800)
		return(0);
	return(1);
}

void tools_click(t_map *map, int x, int y)
{
	if ((x > 80 &&  x < 110) && y > 60 && y < 90)
		edit_tool(map, 6);
	else if ((x > 130 &&  x < 160) && y > 60 && y < 90)
		edit_tool(map, 7);
	else if ((x > 180 &&  x < 210) && y > 60 && y < 90)
		edit_tool(map, 8);
}

int widget_click(t_map *map, int x, int y)
{
	int tmp;

	tmp = map->wclick;
	if ((x > 70 && x < 95) && y > 140 && y < 165)
		map->wclick -= 3;
	else if ((x > 195 && x < 220) && y > 140 && y < 165)
		map->wclick += 3;
	if (map->wclick != tmp)
		return (0);
	return (1);
}

void section_click(t_map *map, int x, int y)
{
	if ((x > 20 &&  x < 90) && y > 20 && y < 50)
		edit_tool(map, 3);
	else if ((x > 110 &&  x < 180) && y > 20 && y < 50)
		edit_tool(map, 4);
	else if ((x > 200 &&  x < 270) && y > 20 && y < 50)
		edit_tool(map, 5);
}

void blockterxture_click(t_map *map, int x, int y)
{
	if ((x > 65 && x < 115) && y > 250 && y < 300)
		edit_blocktexture(map, 0);
	else if ((x > 165 && x < 215) && y > 250 && y < 300)
		edit_blocktexture(map, 1);
	else if ((x > 65 && x < 115) && y > 320 && y < 370)
		edit_blocktexture(map, 2);
	else if ((x > 165 && x < 215) && y > 250 && y < 370)
		edit_blocktexture(map, 3);
}

void catch_click(t_map *map, int x, int y)
{
	section_click(map, x, y);
	tools_click(map, x, y);
	blockterxture_click(map, x, y);
	if (!widget_click(map, x, y))
		remove_blocks(map);
}
