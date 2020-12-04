#include "../include/map.h"

void i_error()
{
	printf("error");
	exit(1);
}

// int zvezd(int n)
// {
// 	if (n < 1)
// 		return (1);
// 	else if (n >= 1)
// 		return (2 +(zvezd(--n) + 2 + zvezd(n -= 2)));
// }

int writedown_map(t_map *map)
{
	t_nod *n;
	int i;

	i = 0;
	n = map->nod;
	while (n)
	{
		//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", n->x1, n->y1, n->x2, n->y2);
		n = n->nxt;
	}
	return (0);
}

int main(int ac, char **av)
{
	// printf("len: %d\n", zvezd(35));
	t_map *map;
	unsigned int t;
	unsigned int t1;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if(!init_all(map))
		i_error();
	draw(map);
	SDL_UpdateWindowSurface(map->win);

	events(map);
	SDL_DestroyWindow(map->win);
	SDL_Quit();
	writedown_map(map);
	return (0);
}
