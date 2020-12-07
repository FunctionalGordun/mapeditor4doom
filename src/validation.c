#include "../include/map.h"

int check_scene(t_info *info, t_map *map) // x = max_x, y = max_y, w = min_x, h = min_y
{
	t_nod *n;
	t_nod *tmp;
	int i;
	
	n = map->nod;
	tmp = map->nod;
	i = 0;
	while (n)
	{
		if (n->x1 == info->x || n->x2 == info->x || n->x1 == info->w || n->x2 == info->w ||
		n->y1 == info->y || n->y2 == info->y || n->y1 == info->h || n->y2 == info->h)
		{
			tmp = n;
			while (tmp)
			{
				if (tmp->x1 == info->x)
					i++;
				else if (tmp->x2 == info->x)
					i++;
				if (tmp->x1 == info->w)
					i++;
				else if (tmp->x2 == info->w)
					i++;
				if (tmp->y1 == info->y)
					i++;
				else if (tmp->y2 == info->y)
					i++;
				if (tmp->y1 == info->h)
					i++;
				else if (tmp->y2 == info->h)
					i++;
				tmp = tmp->nxt;
			}
			printf("i: %d\n", i);
			if (i == 8 || i == 12 || i == 11 || i == 10) // ????????????maybe
			{
				printf("that's cool map!\n");
				return(1);
			}
			else
			{
				map->inter_tex[21]->active = 0;
				map->validflag = 1;
				events(map);
			}
			break ;
		}
		n = n->nxt;
	}
	return (0);
}

char **write_n(t_map *map, t_nod *n, char **arr)
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

	if (n)
	{
		x1 = n->x1 + map->z_x;
		x2 = n->x2 + map->z_x;
		// if (x1 < 0 && x2 < 0)
		// 	return;
		y1 = n->y1 + map->z_y;
		y2 = n->y2 + map->z_y;
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
				arr[j][i] = '1';
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
				arr[j][i] = '1';
				er += de;
				if (er >= dy + 1)
				{
					j += diry;
					er = er - (dy + 1);
				}
				i += di;
			}
		}
	}
	return (arr);
}
void	bzero_map(void *b, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *)b;
	while (n--)
		*arr++ = '0';
}

void make_emptymap(t_info *info, t_map *map, int fd)
{
	int x;
	int y;
	int i;
	int j;
	char *buffer;
	

	x = info->x - info->w;
	y = info->y - info->h;
	printf("x: %d, y: %d\n", x, y);
	buffer = malloc(sizeof(char *) * (x + 1));
	bzero_map(buffer, x);
	i = 0;
	while (i < y)
	{
		if (write(fd, buffer, x) != x)
			printf("errorororor\n");
		write(fd, "\n", 1);
		// j = 0;
		// while (j < x)
		// {
		// 	write(fd, '0', x) != x;
		// }
		i++;
	}
	
}

char **test(t_info *info, t_map *map)
{
	int x;
	int y;
	int i;
	int j;

	x = info->x - info->w;
	y = info->y - info->h;
	printf("x: %d, y: %d\n", x, y);
	char **arr;
	arr = malloc(sizeof(char *) * y);
	i = 0;
	while (i < y)
	{
		j = 0;
		arr[i] = malloc(sizeof(char *) * x);
		while (j < x)
		{
			arr[i][j] = '0';
			j++;
		}
		i++;
	}
	return (arr);
}

void write_nodes(t_info *info, t_map *map)
{
	t_nod *n;
	char *buffer;
	char **arr;

	n = map->nod;
	int fd;
	if ((fd=open("./maps/test.txt", O_WRONLY))==-1)
	{
		printf ("Cannot open file.\n");
		exit(1);
	}
	if (!n)
		return ;
	//make_emptymap(info, map, fd);
	printf("1\n");
	arr = test(info, map);
	printf("2\n");
	int i = 0;
	int j = 0;

	while (i < (info->y - info->h))
	{
		j = 0;
		while (j < (info->x - info->w))
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("3\n");
	while (n)
	{
		arr = write_n(map, n, arr);
		n = n->nxt;
	}
	printf("4\n");
	i = 0;
	j = 0;

	while (i < (info->y - info->h))
	{
		j = 0;
		while (j < (info->x - info->w))
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	close(fd);
}

int valid_map(t_map *map)
{
	t_nod *n;
	int max_x;
	int max_y;
	int min_x;
	int min_y;
	
	n = map->nod;
	max_x = -WIDTH;
	max_y = -HEIGHT;
	min_x = WIDTH;
	min_y = HEIGHT;
	while (n)
	{
		if (n->x1 >= max_x)
			max_x = n->x1;
		else if (n->x2 >= max_x)
			max_x = n->x2;
		if (n->x1 <= min_x)
			min_x = n->x1;
		else if (n->x2 <= min_x)
			min_x = n->x2;
		if (n->y1 >= max_y)
			max_y = n->y1;
		else if (n->y2 >= max_y)
			max_y = n->y2;
		if (n->y1 <= min_y)
			min_y = n->y1;
		else if (n->y2 <= min_y)
			min_y = n->y2;
		n = n->nxt;
	}
	if (check_scene(&(t_info){max_x, max_y, min_x, min_y}, map))
	{
		//write_nodes(&(t_info){max_x, max_y, min_x, min_y}, map);
		return (1);
	}
	printf("max x: %d y: %d\n", max_x, max_y);
	printf("min x: %d y: %d\n", min_x, min_y);
	return (0);
}