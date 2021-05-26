#include <iostream>
#include <algorithm>
using namespace std;
void quicksort(int *num, int left, int right);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int a[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	random_shuffle(a, a + n);
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\n";
	}
}

void quicksort(int *num, int left, int right) {
	int pivot, temp, i, j;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = num[left];
		do {
			do { i++; } while (num[i] < pivot&&i <= right);
			do { j--; } while (num[j] > pivot&&j >= left);
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
