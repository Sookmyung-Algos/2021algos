#include <iostream>
#define arr_size 1001
using namespace std;

// insertion sort
void insertion_sort(int list[], int n) {
	int i, j, next;
	for (int i = 1; i < n; i++) { // 첫 번째 원소는 정렬된 것으로 보고 두 번째 원소부터 삽입
		next = list[i];
		for (j = i - 1; j >= 0 && next < list[j]; j--) // 이전 값보다 작으면
			list[j + 1] = list[j]; // 바꾸기
		list[j + 1] = next;
	}
}

int main() {

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num; // n개의 수 입력

	int arr[arr_size];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	insertion_sort(arr, num);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
