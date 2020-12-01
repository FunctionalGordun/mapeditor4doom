#include "../include/map.h"

void	get_floorsky_texture(t_map *map)
{
	map->floorsky_tex[0]->img = IMG_Load("/textures/interface/blackblock.png");
	map->floorsky_tex[1]->img = IMG_Load("/textures/floor/floor1.png");
	map->floorsky_tex[2]->img = IMG_Load("/textures/floor/floor2.png");
	map->floorsky_tex[3]->img = IMG_Load("/textures/floor/floor3.png");
	map->floorsky_tex[4]->img = IMG_Load("/textures/floor/floor4.png");
	map->floorsky_tex[5]->img = IMG_Load("/textures/floor/sky1.png");
	map->floorsky_tex[6]->img = IMG_Load("/textures/floor/sky2.png");
	map->floorsky_tex[7]->img = IMG_Load("/textures/floor/sky3.png");
	map->floorsky_tex[8]->img = IMG_Load("/textures/floor/sky4.png");
	map->floorsky_tex[9]->img = IMG_Load("/textures/floor/floor5.png");
	map->floorsky_tex[10]->img = IMG_Load("/textures/floor/floor6.png");
	map->floorsky_tex[11]->img = IMG_Load("/textures/floor/floor7.png");
	map->floorsky_tex[12]->img = IMG_Load("/textures/floor/floor8.png");
}

void	malloc_floorsky_texture(t_map *map)
{
	int i;

	i = -1;
	while (++i < 13)
		map->floorsky_tex[i] = (t_image *)malloc(sizeof(t_image));
	get_floorsky_texture(map);
	i = -1;
	while (++i < 13)
	{
		map->floorsky_tex[i]->img = SDL_ConvertSurfaceFormat(map->floorsky_tex[i]->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->floorsky_tex[i]->img, &(map->floorsky_tex[i]->s), &(map->floorsky_tex[i]->pixb), &(map->floorsky_tex[i]->strb));
		map->floorsky_tex[i]->active = 0;
	}
}

void	get_wall_texture(t_map *map)
{
	map->wall_tex[0]->img = IMG_Load("/textures/interface/blackblock.png");
	map->wall_tex[1]->img = IMG_Load("/textures/walls/wall0.png");
	map->wall_tex[2]->img = IMG_Load("/textures/walls/wall1.png");
	map->wall_tex[3]->img = IMG_Load("/textures/walls/wall2.png");
	map->wall_tex[4]->img = IMG_Load("/textures/walls/wall3.png");
	map->wall_tex[5]->img = IMG_Load("/textures/walls/wall4.png");
	map->wall_tex[6]->img = IMG_Load("/textures/walls/wall5.png");
	map->wall_tex[7]->img = IMG_Load("/textures/walls/wall6.png");
	map->wall_tex[8]->img = IMG_Load("/textures/walls/wall7.png");
	map->wall_tex[9]->img = IMG_Load("/textures/walls/wall8.png");
	map->wall_tex[10]->img = IMG_Load("/textures/walls/wall9.png");
	map->wall_tex[11]->img = IMG_Load("/textures/walls/wall10.png");
	map->wall_tex[12]->img = IMG_Load("/textures/walls/wall11.png");
	map->wall_tex[13]->img = IMG_Load("/textures/walls/wall12.png");
	map->wall_tex[14]->img = IMG_Load("/textures/walls/wall13.png");
	map->wall_tex[15]->img = IMG_Load("/textures/walls/wall14.png");
	map->wall_tex[16]->img = IMG_Load("/textures/walls/wall15.png");
	map->wall_tex[17]->img = IMG_Load("/textures/walls/wall16.png");
	map->wall_tex[18]->img = IMG_Load("/textures/walls/wall17.png");
	map->wall_tex[19]->img = IMG_Load("/textures/walls/wall18.png");
}

void	malloc_wall_texture(t_map *map)
{
	int i;

	i = -1;
	while (++i < 20)
		map->wall_tex[i] = (t_image *)malloc(sizeof(t_image));
	get_wall_texture(map);
	i = -1;
	while (++i < 20)
	{
		map->wall_tex[i]->img = SDL_ConvertSurfaceFormat(map->wall_tex[i]->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->wall_tex[i]->img, &(map->wall_tex[i]->s), &(map->wall_tex[i]->pixb), &(map->wall_tex[i]->strb));
		map->wall_tex[i]->active = 0;
	}
}

void draw_floorsky_texture(t_map *map)
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
		draw_img(map, &(t_info){x, y, 50, 50}, map->floorsky_tex[i]);
		x += 60;
		if (i == 4)
		{
			x = 20;
			y = 400;
		}
	}
}


		// if (map->wall_tex[i]->active)
		// 	draw_img(map, &(t_info){x, y, 50, 50}, map->inter_tex[9]);
void draw_wall_texture(t_map *map)
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
		draw_img(map, &(t_info){x, y, 50, 50}, map->wall_tex[i]);
		x += 60;
		if (i == 4)
		{
			x = 20;
			y = 230;
		}
	}
}

void	showtexture(t_map *map)
{
	int i;
	int y;

	i = 8;
	y = 20;
	while (++i < 19)
	{
		draw_img(map, &(t_info){320, y, 50, 50}, map->wall_tex[i]);
		y += 80;
	}
}

void showupcontent(t_map *map)
{
	int i;
	int y;

	i = 8;
	y = 20;
	if (map->showactive == 1)
		showtexture(map);
}

void draw_showuppanel(t_map *map, int x, int y)
{
	if (map->inter_tex[13]->active == 1)
	{
		draw_img(map, &(t_info){x, y, 30, 50}, map->inter_tex[14]);
		draw_img(map, &(t_info){305, 0, 80, 800}, map->inter_tex[12]);
		showupcontent(map);
	}
	else
		draw_img(map, &(t_info){x, y, 30, 50}, map->inter_tex[13]);
}

void	texture_block(t_map *map)
{
	draw_wall_texture(map);
	draw_showuppanel(map, 260, 205);
	draw_floorsky_texture(map);
	draw_showuppanel(map, 260, 370);
}