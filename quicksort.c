#include <stdio.h>
#include <stdlib.h>
#define SHOW_PASS

void swap(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort_recursive(int *a, int start, int end) {
	if (start >= end)
		return;
	int mid = a[start];
	int left = start + 1, right = end;
	while (left < right) {
		while (a[right] >= mid && right > left) {
			right--;
		}
		while (a[left] <= mid && left < right) {
			left++;
		}
		swap(&a[left], &a[right]);
	}
	if (a[left] <= mid)
		swap(&a[start], &a[left]);

#ifdef SHOW_PASS
	printf("PASS:");
	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
#endif

	quicksort_recursive(a, start, left - 1);
	quicksort_recursive(a, right, end);
}

int quicksort(int *a, int len) {
	quicksort_recursive(a, 0, len);
	return 1;
}

int main(int argc, char const *argv[])
{
	int a[6] = { 5,2,7,6,4,9 };
	int rc = quicksort(a, 5);
	int i = 0;

	for (i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
