#include "../include/map.h"

void i_error()
{
	printf("error");
	exit(1);
}

void check_scene(int max_x, int max_y, int min_x, int min_y, t_map *map)
{
	t_nod *n;
	t_nod *tmp;
	int i;
	
	n = map->nod;
	tmp = map->nod;
	i = 0;
	while (n)
	{
		if (n->x1 == max_x || n->x2 == max_x || n->x1 == min_x || n->x2 == min_x ||
		n->y1 == max_y || n->y2 == max_y || n->y1 == min_y || n->y2 == min_y)
		{
			tmp = n;
			while (tmp)
			{
				if (tmp->x1 == max_x)
					i++;
				else if (tmp->x2 == max_x)
					i++;
				if (tmp->x1 == min_x)
					i++;
				else if (tmp->x2 == min_x)
					i++;
				if (tmp->y1 == max_y)
					i++;
				else if (tmp->y2 == max_y)
					i++;
				if (tmp->y1 == min_y)
					i++;
				else if (tmp->y2 == min_y)
					i++;
				tmp = tmp->nxt;
			}
			printf("i: %d\n", i);
			if (i == 8 || i == 12 || i == 11 || i == 10) // ????????????maybe
				printf("that's cool map!\n");
			else
				printf("close your fucking map!\n");
			break ;
		}
		n = n->nxt;
	}
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
	check_scene(max_x, max_y, min_x, min_y, map);
	// printf("max x: %d y: %d\n", max_x, max_y);
	// printf("min x: %d y: %d\n", min_x, min_y);
	return (0);
}

int writedown_map(t_map *map)
{
	t_nod *n;
	int strl;
	int maxlen;
	char *buffer;

	n = map->nod;
	int fd;

	if ((fd=open("./maps/test.txt", O_WRONLY))==-1)
	{
		printf ("Cannot open file.\n");
		exit(1);
	}
	while (n)
	{
		maxlen = ft_strlen(ft_itoa((int)n->x1)) + ft_strlen(ft_itoa((int)n->y1)) + ft_strlen(ft_itoa((int)n->x2)) + ft_strlen(ft_itoa((int)n->y2));
		buffer = malloc(sizeof(char *) * (maxlen + 4));
		buffer = ft_itoa((int)n->x1);
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y1));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->x2));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y2));
		buffer = ft_strjoin(buffer, "\n");
		if(write(fd, buffer, maxlen + 4) != maxlen + 4)
			printf("error\n");
		free(buffer);
		//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", n->x1, n->y1, n->x2, n->y2);
		n = n->nxt;
	}
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	t_map *map;
	unsigned int t;
	unsigned int t1;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if(!init_all(map))
		i_error();
	draw(map);
	SDL_UpdateWindowSurface(map->win);

	if (events(map) == 1)
	{
		valid_map(map);
		writedown_map(map);
	}
	SDL_DestroyWindow(map->win);
	SDL_Quit();
	return (0);
}
