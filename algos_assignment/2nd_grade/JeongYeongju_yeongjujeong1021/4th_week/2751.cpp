#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 1000001
using namespace std;

int arr[MAX];

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void quick_sort(int arr[], int left, int right) {
	int l, r, p, pivot;

	if (left < right) {
		p = rand() % (right - left) + left; // 랜덤으로 pivot 결정
		pivot = arr[p];
		swap(arr[p], arr[left]);
		l = left;
		r = right + 1;
		do {
			do { l++; } while (arr[l] < pivot && l <= right);
			do { r--; } while (arr[r] > pivot && r >= left);
			if (l < r)
				swap(arr[l], arr[r]);
		} while (l < r);
		swap(arr[left], arr[r]);

		quick_sort(arr, left, r - 1);
		quick_sort(arr, r + 1, right);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	srand((unsigned int)time(NULL));

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}
