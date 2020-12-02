#include "../include/map.h"

void draw_floorsky_textures(t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 20;
	y = 340;
	draw_img(map, &(t_info){50, 300, 200, 30}, map->floorsky_tex[0]);
	fonts_doom(map, "FLOOR & SKY", 90, 307, REDFONT);
	while (++i < 9)
	{
		if (map->floorsky_tex[i]->active == 1)
			draw_img(map, &(t_info){x - 10, y - 10, 70, 70}, map->inter_tex[15]);
		draw_img(map, &(t_info){x, y, 50, 50}, map->floorsky_tex[i]);
		x += 60;
		if (i == 4)
		{
			x = 20;
			y = 400;
		}
	}
}

void draw_wall_textures(t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 20;
	y = 170;
	draw_img(map, &(t_info){50, 125, 200, 30}, map->wall_tex[0]);
	fonts_doom(map, "WALLS", 120, 132, REDFONT);
	while (++i < 9)
	{
		if (map->wall_tex[i]->active == 1)
			draw_img(map, &(t_info){x - 10, y - 10, 70, 70}, map->inter_tex[15]);
		draw_img(map, &(t_info){x, y, 50, 50}, map->wall_tex[i]);
		x += 60;
		if (i == 4)
		{
			x = 20;
			y = 230;
		}
	}
}
void draw_liquid_textures(t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 20;
	y = 520;
	draw_img(map, &(t_info){50, 475, 200, 30}, map->liquid_tex[0]);
	fonts_doom(map, "LIQUIDS", 110, 482, REDFONT);
	while (++i < 4)
	{
		if (map->liquid_tex[i]->active == 1)
			draw_img(map, &(t_info){x - 10, y - 10, 70, 70}, map->inter_tex[15]);
		draw_img(map, &(t_info){x, y, 50, 50}, map->liquid_tex[i]);
		x += 90;
	}
}