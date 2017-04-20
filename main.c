#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W_SIZE_X 10
#define W_SIZE_Y 10

void world_init(/* Recibo un mundo */);
void world_print(bool w[W_SIZE_X][W_SIZE_Y]);
void world_step(/* Recibo dos mundos */);
int world_count_neighbors(/* Recibo un mundo y unas coordenadas */);
bool world_get_cell(/* Recibo un mundo y unas coordenadas */);
void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y]);

int main()
{
	int i = 0;
	bool world_a[W_SIZE_X][W_SIZE_Y];
	bool world_b[W_SIZE_X][W_SIZE_Y];

	world_init(world_a);
	do {
		printf("\033cIteration %d\n", i++);
		world_print(world_a);
		// TODO: Itera
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y])
{
	//Inicializacion de la matriz
	for(int i = 0; i < W_SIZE_X; i++){
		for(int j = 0; j < W_SIZE_Y; j++){
			world_a[i][j] = false;
		}
	}
	
	//Inicializacion del patron
	world_a[0][1] = true;
	world_a[1][2] = true;
	world_a[2][0] = true;
	world_a[2][1] = true;
	world_a[2][2] = true;
	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
}

void world_print(bool w[W_SIZE_X][W_SIZE_Y])
{
	for (int i = 0; i < W_SIZE_X; i++) {
		for (int j = 0; j < W_SIZE_Y; j++)
			printf("%s", w[i][j] ? " #" : " .");
		printf("\n");
	}
	printf("\n");
}

void world_step(/* Recibo dos mundos */)
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
}

int world_count_neighbors(/* Recibo un mundo y unas coordenadas */)
{
	// Devuelve el número de vecinos
}

bool world_get_cell(/* Recibo un mundo y unas coordenadas */)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
}

void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y])
{
	//Copia el segundo mundo (world_b) sobre el primero (world_a)
	for(int i = 0; i < W_SIZE_X; i++){
		for(int j = 0; j < W_SIZE_Y; j++){
			world_a[i][j]=world_b[i][j];
		}
	}
}
