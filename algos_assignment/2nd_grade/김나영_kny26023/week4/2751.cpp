#include <iostream>
#include <algorithm>
using namespace std;
 
void quick_sort(int *arr, int start, int end){
	int pivot = arr[start];
	int left = start + 1;
	int right = end;
 
	if (start >= end)
		return;
	while (true) {
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && arr[right] >= pivot)
			right--;
		if (left > right)
			break;
		swap(arr[left], arr[right]);
	}
	swap(arr[start], arr[right]);
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}
//퀵정렬 코드 (재귀문을 활용했다)
 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int N;
	int arr[1000000];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
    }
 
	random_shuffle(arr, arr + N);
  //이부분이 중요한데, 이부분을 주석처리하면 시간 초과가 난다. 퀵정렬의 특성 때문에 꼭 넣어주어야 한다.
	quick_sort(arr, 0, N - 1);
    
	for (int i = 0; i < N; i++){
		cout << arr[i] << '\n';
    }
 
	return 0;
}
