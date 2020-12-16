#include "../include/map.h"
char *count_floor(t_map *map, int fd);

void write_ceilingfloor(t_map *map, int fd)
{
	t_nod *n;
	int maxlen;
	char *buffer;
	char *str_f;
	char *str_c;

	n = map->nod;
	while (n)
	{


		n = n->nxt;
	}
	// maxlen = ft_strlen("walls: ") + ft_strlen(ft_itoa(num_w)) + 1;
	// buffer = malloc(sizeof(char *) * (maxlen));
	// buffer = "walls: ";
	// buffer = ft_strjoin(buffer, ft_itoa(num_w));
	// buffer = ft_strjoin(buffer, "\n");
	// if (write(fd, buffer, maxlen) != maxlen)
	// 	printf("error\n");
	free(buffer);
}

void count_write(t_map *map, int fd)
{
	t_nod *n;
	int maxlen;
	char *buffer;
	int num_w;

	num_w = 0;
	n = map->nod;
	while (n)
	{
		if (ft_strcmp(n->texture->type_name, "wall"))
			num_w++;
		n = n->nxt;
	}
	maxlen = ft_strlen("walls: ") + ft_strlen(ft_itoa(num_w)) + ft_strlen(count_floor(map, fd)) + 2; // ft_strlen(count_floor(map, fd))
	buffer = malloc(sizeof(char *) * (maxlen));
	buffer = "walls: ";
	buffer = ft_strjoin(buffer, ft_itoa(num_w));
	buffer = ft_strjoin(buffer, "\t");
	buffer = ft_strjoin(buffer, count_floor(map, fd));
	buffer = ft_strjoin(buffer, "\n");
	printf("return: %s\n",count_floor(map, fd));
	if (write(fd, buffer, maxlen) != maxlen)
		printf("error\n");
	free(buffer);
}

char *count_floor(t_map *map, int fd)
{
	int i;
	int tmp;
	int omp;
	char *buffer;

	i = -1;
	tmp = 0;
	omp = 0;
	while (++i < 8)
	{
		if (map->floorstr[i])
			tmp++;
		if (map->ceilingstr[i])
			omp++;
	}
	// printf("tmp %d\n", tmp);
	// if (tmp && omp)
	// 	buffer = malloc(sizeof(char *) * (ft_strlen(ft_itoa(tmp)) + ft_strlen(ft_itoa(omp)) + 2));
	// else if (tmp && !omp)
	// 	buffer = malloc(sizeof(char *) * (ft_strlen(ft_itoa(tmp)) + 1));
	// buffer = malloc(sizeof(char *) * (ft_strlen(ft_itoa(tmp)) + 1));
	// while (i < 9)
	// {
	// 	// printf("arr%d : %d\n", i, arr[i]);
	// 	if (arr[i] != 0)
	// 		num_f++;
	// 	i++;
	// }
	if (tmp)
	{
		buffer = ft_strjoin("floor: ", ft_itoa(tmp));
		buffer = ft_strjoin(buffer, "\t");
	}
	if (omp)
	{
		if(!tmp)
			buffer = ft_strjoin("ceiling: ", ft_itoa(omp));
		else
			buffer = ft_strjoin(buffer, "ceiling: ");
		buffer = ft_strjoin(buffer, ft_itoa(omp));
		// buffer = ft_strjoin(buffer, "\t");
	}
	printf("buffer: %s|\n", buffer);
	return (buffer);
}


// char *count_floor(t_map *map, int fd)
// {
// 	t_nod *n;
// 	char *buffer;
// 	int num_f;
// 	char *tmp;
// 	int arr[9];
// 	int i;

// 	num_f = 0;
// 	ft_izero(arr, 9);
// 	n = map->nod;
// 	while (n)
// 	{
// 		if (n->texture->floor_name != NULL)
// 		{
// 			i = 1;
// 			tmp = malloc(sizeof(char *) * 1000);
// 			while (i < 9)
// 			{
// 				tmp = ft_strjoin(ft_strjoin("floor", ft_itoa(i)), ".png");
// 				if (!ft_strcmp(n->texture->floor_name, tmp))
// 				{
// 					arr[i]++;
// 					break ;
// 				}
// 				i++;
// 			}
// 		}
// 		n = n->nxt;
// 	}
// 	i = 1;
// 	buffer = malloc(sizeof(char *) * (ft_strlen(ft_itoa(num_f)) + 8));
// 	while (i < 9)
// 	{
// 		// printf("arr%d : %d\n", i, arr[i]);
// 		if (arr[i] != 0)
// 			num_f++;
// 		i++;
// 	}
// 	buffer = ft_strjoin("floor: ", ft_itoa(num_f));
// 	buffer = ft_strjoin(buffer, "\t");
// 	//printf("buffer: %s\n", buffer);
// 	return (buffer);
// }

void write_walls(t_map *map, int fd)
{
	t_nod *n;
	int maxlen;
	char *buffer;

	n = map->nod;
	while (n)
	{
		// if (n->texture->floor_name != NULL)
		// 	printf("floor name: %s\n", n->texture->floor_name);
		// if (n->texture->ceiling_name != NULL)
		// 	printf("ceiling name: %s\n", n->texture->ceiling_name);
		// if (n->texture->texture_name[1] != NULL)
		// 	printf("texture name: %s\n", n->texture->texture_name[1]);
		// if (n->texture->type_name != NULL)
		// 	printf("name: %s\n", n->texture->type_name);
		maxlen = ft_strlen(ft_itoa((int)n->x1)) + ft_strlen(ft_itoa((int)n->y1)) + ft_strlen(ft_itoa((int)n->x2)) + ft_strlen(ft_itoa((int)n->y2)) + 4;
		if (n->texture->texture_name[0] != NULL)
			maxlen += ft_strlen(n->texture->texture_name[0]) + 1;
		if (n->texture->texture_name[1] != NULL)
			maxlen += ft_strlen(n->texture->texture_name[1]) + 1;
		if (n->texture->type_name != NULL)
			maxlen += ft_strlen(n->texture->type_name) + 1;
		// printf("maxlen: %d\n", maxlen);
		buffer = malloc(sizeof(char *) * (maxlen));
		if (n->texture->type_name != NULL)
		{
			buffer = n->texture->type_name;
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, ft_itoa((int)n->x1));
		}
		else
			buffer = ft_itoa((int)n->x1);
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y1));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->x2));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y2));
		if (n->texture->texture_name[0] != NULL)
		{
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, n->texture->texture_name[0]);
		}
		if (n->texture->texture_name[1] != NULL)
		{
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, n->texture->texture_name[1]);
		}
		buffer = ft_strjoin(buffer, "\n");
		if(write(fd, buffer, maxlen) != maxlen)
			printf("error\n");
		free(buffer);
		//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", n->x1, n->y1, n->x2, n->y2);
		n = n->nxt;
	}
}

int writedown_map(t_map *map)
{
	int fd;

	if ((fd=open("./maps/test.txt", O_WRONLY))==-1)
	{
		printf ("Cannot open file.\n");
		exit(1);
	}
	count_write(map, fd);
	write_walls(map, fd);
	// count_floor(map, fd);
	// write_ceilingfloor(map, fd);
	close(fd);
	return (0);
}