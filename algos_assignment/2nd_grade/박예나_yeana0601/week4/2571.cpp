//퀵정렬
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int* num, int, int);

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int a[1000001], cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) cin >> a[i];
	random_shuffle(a, a + cnt);
//이미 정렬된 경우(최악)을 막기 위해 shuffle
  
	quicksort(a, 0, cnt-1);
  
	for (int i = 0; i < cnt; i++) cout << a[i] << '\n';
	return 0;
}

void quicksort(int* num, int left, int right) {
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
