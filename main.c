#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	bool world_a[W_SIZE_X][W_SIZE_Y];
	bool world_b[W_SIZE_X][W_SIZE_Y];

	world_init(world_a);
	do {
		printf("\033cIteration %d\n", i++);
		world_print(world_a);
		// Itera
		world_step(world_a, world_b);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}


