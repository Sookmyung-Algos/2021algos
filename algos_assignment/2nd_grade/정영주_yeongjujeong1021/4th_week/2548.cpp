#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 20001
using namespace std;

int arr[MAX];

void quick_sort(int left, int right) {
	int l, r, p, pivot;

	if (left < right) {

		p = rand() % (right - left + 1) + left;
		pivot = arr[p];
		swap(arr[p], arr[left]);

		l = left;
		r = right + 1;

		do {
			do { l++; } while (arr[l] <= pivot && l <= right);
			do { r--; } while (arr[r] > pivot && r >= left);

			if (l < r) swap(arr[l], arr[r]);

		} while (l < r);

		swap(arr[r], arr[left]);

		quick_sort(left, r - 1);
		quick_sort(r + 1, right);

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

	quick_sort(0, n - 1);

	cout << arr[(n - 1) / 2] << '\n';

	return 0;
}
