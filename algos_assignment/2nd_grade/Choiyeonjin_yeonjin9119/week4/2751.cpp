#include <iostream>
using namespace std;
//퀵정렬을 사용하여 문제를 풀게되면 시간초과로 정답처리가 되지 않지만, 스터디시간에 퀵정렬을 적용하여 한번 풀어보라고 하셔서 퀵정렬의 방식을 채택하여 풀어봄
void quicksort(int num[], int left, int right) {
	int pivot, i, j, temp;
	if (left < right) {
		i = left;
		j = right+1;
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
int main() {
	cin.tie(NULL); 
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	int* arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	quicksort(arr, 0, num - 1);
	for (int i = 0; i < num; i++) {
		cout << arr[i]<<"\n";
	}
}
