#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#define W_SIZE_X 10
#define W_SIZE_Y 10

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y]);
void world_print(bool w[W_SIZE_X][W_SIZE_Y]);
void world_step(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y]);
static int world_count_neighbors(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j);
static bool world_get_cell(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j);
static void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y]);

#endif
