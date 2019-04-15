#include <stdio.h>
#include <stdlib.h>
#define SENTINEL 10000
#define SHOW_PASS

void swap(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *a, int start, int end) {
	if (start > end) 
		return;
	int i = 0;
	int dad = start;
	int son = 2 * start;
	while (son <= end) {
		if (son + 1 <= end && a[son] < a[son+1]) {
			son++;
		}
		if (a[son] > a[dad])
			swap(&a[son], &a[dad]);
		dad = son;
		son = 2 * dad;
	}
}

void heap_create(int *a, int start, int end) {
	int i = 0;
	for (i = end/2; i >= 1; i--) {
		heapify(a, i, end);
	}
}

int my_heapsort(int *a, int start, int end) {
	int i = 0;
	for (i = end; i > 1; i--) {
		swap(&a[i], &a[1]);
		heap_create(a, 1, i - 1);
	}
	
	return 1;
}

int main(int argc, char const *argv[])
{
	int a[8] = { SENTINEL,16,8,990,7,1,4,2 };
	heap_create(a, 1, 7);

	int rc = my_heapsort(a, 1, 7);
	int i = 0;
	for (i = 1; i < 8; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}