#include <iostream>
using namespace std;
//quick sort 시간초과?

void merge(int* arr, int* sorted, int begin, int middle, int end);
void mergesort(int* arr, int* sorted, int begin, int end);

int main() {
	int temp;
	int n;
	cin >> n;

	int* arr = new int[n]; // 배열 arr에 동적할당 new 사용
	for (int i = 0; i < n; i++) cin >> arr[i];
	int* sorted = new int[n];

	mergesort(arr, sorted, 0, n - 1);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}

void merge(int* arr, int* sorted, int begin, int middle, int end) {
	int sortedi = begin;
	int i = begin;
	int j = middle + 1;

	while (i <= middle && j <= end) {
		if (arr[i] < arr[j]) sorted[sortedi] = arr[i++];
		else  sorted[sortedi] = arr[j++];
		sortedi++;
	}
	
	if (i > middle) {// 왼쪽 < 오른쪽
		while (j <= end)	sorted[sortedi++] = arr[j++];
	}
	if (j > end) {// 왼쪽 > 오른쪽
		while (i <= middle)	sorted[sortedi++] = arr[i++];
	}
	for (int k = begin; k <= end; k++) arr[k] = sorted[k];
}

void mergesort(int* arr, int* sorted, int begin, int end) {
	int middle;
	if (begin < end) {
		middle = (begin + end) / 2;
		mergesort(arr, sorted, begin, middle);
		mergesort(arr, sorted, middle + 1, end);
		merge(arr, sorted, begin, middle, end);
	}
}
