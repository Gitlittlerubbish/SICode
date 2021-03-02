#include <stdio.h>
#include <time.h>

int main()
{
	FILE *file = fopen("./time_test.txt", "w+");
	int n = 100;
	clock_t start, end;
	start = clock();
	int a = 0;
	while (n--) {
		//fprintf(file, "n==%d\n", n);
		a++;
	}
	end = clock();
	printf("time is %fs\n", (double)(end - start)/CLOCKS_PER_SEC);

	fclose(file);	
	return 0;
}
