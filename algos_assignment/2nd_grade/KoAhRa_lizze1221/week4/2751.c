#include <stdio.h>

void quicksort(int num[], int left, int right) {
	int pivot, i, j, temp;

	if (left < right) {
		i = left;
		j = right + 1;
		pivot = num[left];

		do {
			do { i++; } while (num[i] < pivot && i <= right);
			do { j--; } while (num[j] > pivot && j >= left);
			if (i < j) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		} while (i < j);
		temp = num[left];
		num[left] = num[j];
		num[j] = temp;

		quicksort(num, left, j - 1);
		quicksort(num, j + 1, right);
	}
}


void main() {
	int num[10000];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	quicksort(num, 0, N);

	for (int j = 1; j < N+1; j++) {
		printf("%d ", num[j]);
	}
}
