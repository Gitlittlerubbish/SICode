#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) 
{
	int **arr, *arr_row;
	
	arr_row = calloc(3 * 2, sizeof(int));
	arr = calloc(2, sizeof(int *));
	
	for (int row = 0; row < 2; row++) {
		arr[row] = arr_row + sizeof(int) * row;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", i * j);
			arr[i][j] = i * j;
		}
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			printf("arr[%d][%d]=%d\n", i, j, arr[i][j]);

	printf("%d\n", arr[0][1]);
	return 0;
}
