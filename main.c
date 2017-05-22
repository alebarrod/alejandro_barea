#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W_SIZE_X 10
#define W_SIZE_Y 10

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y]);
void world_print(bool w[W_SIZE_X][W_SIZE_Y]);
void world_step(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y]);
int world_count_neighbors(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j);
bool world_get_cell(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j);
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
		// Itera
		world_step(world_a,world_b);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y])
{
	//Inicializacion de la matriz
	for (int i = 0; i < W_SIZE_X; i++){
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
	/* Inicializar con el patrón del glider:
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

void world_step(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y])
{
	/*
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
	
	//Comprobamos el estado de cada célula en la siguiente iteración y lo guardamos en world_b.
	for (int i = 0; i < W_SIZE_X; i++) {
		for (int j = 0; j < W_SIZE_Y; j++) {
			world_b[i][j] = world_get_cell(world_a,i,j);
		}
	}
	
	//Aplicamos los cambios a la matriz principal world_a.
	world_copy(world_a,world_b);
	
}

int world_count_neighbors(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j)
{
	//Cuenta las células vivas adyacentes a la célula correspondiente a las coordenadas de i j en la matriz world_a
	int cont = 0;
	
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			if (!(k+i < 0 || k+i > W_SIZE_X-1 || t+j < 0 ||t+j > W_SIZE_Y-1||(k==0 && t==0))) {
				cont = cont + world_a[k+i][t+j];
			}
		}
	}
	
			
	return cont;
}

bool world_get_cell(bool world_a[W_SIZE_X][W_SIZE_Y],int i,int j)
{
	/*	Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	bool res = false;
	int cont = 0;
	
	cont = world_count_neighbors(world_a,i,j);
	
	if (world_a[i][j] == false) {
		res = (cont == 3);
	} else {
		if (cont >= 2 && cont <= 3) {
			res = true;
		}
	}
	return res;
}

void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y],bool world_b[W_SIZE_X][W_SIZE_Y])
{
	//Copia el segundo mundo (world_b) sobre el primero (world_a)
	for (int i = 0; i < W_SIZE_X; i++) {
		for (int j = 0; j < W_SIZE_Y; j++) {
			world_a[i][j] = world_b[i][j];
		}
	}
}
