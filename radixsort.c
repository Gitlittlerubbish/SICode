#include <stdio.h>
#include <stdlib.h>
#define BASE 10
#define SHOWPASS

int a[7] = { 16,8,10,7,1,4,2 };
#define LENGTH 7

int find_max(int *a) {
	int max = 0;
	for (int i = 0; i < LENGTH; i++) {
		max = max > a[i] ? max : a[i];
	}

	return max;
}

int my_radixsort(int *a, int max) {
	int EXP = 1;
	while (max/EXP) {
		int buckets[10] = { 0 };
		int b[7] = { 0 };

		for (int i = 0; i < LENGTH; i++) {
			buckets[a[i]/EXP % BASE]++;
		}

		int s = 0;
		int c = 0;
		//计算比当前小的有多少个，用于存放在b对应下标处。
		for (int i = 0; i < 10; i++)
		{
			c = buckets[i];
			buckets[i] = s;
			s += c;
		}


		for (int i = 0; i < LENGTH; i++) {
			b[buckets[a[i]/EXP % BASE]++] = a[i];
		}

		for (int i = 0; i < LENGTH; i++)
		{
			a[i] = b[i];
		}

		EXP *= BASE;
	}

	return 1;
}

int main(int argc, char const *argv[])
{
	int EXP = 1;
	int max = find_max(a);

	int rc = my_radixsort(a, max);

	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
