#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int arr[1000005];
int temp[1000005];
int N;
long long ans;

void merge_sort(int left, int mid, int right){
	int low = left;
	int high = mid + 1;
	int k = left;

	while (low <= mid && high <= right){
		if (arr[low] <= arr[high]){
			temp[k++] = arr[low++];
		}
		else{
			ans += (mid - low + 1);
			temp[k++] = arr[high++];
		}
	}

	if (high <= right){
		for (int i = high; i <= right; i++){
			temp[k++] = arr[i];
		}
	}
	if (low <= mid){
		for (int i = low; i <= mid; i++){
			temp[k++] = arr[i];
		}
	}

	for (int i = left; i <= right; i++){
		arr[i] = temp[i];
	}
}

void merge(int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);
		merge_sort(left, mid, right);
	}
}

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	merge(1, N);
	cout << ans << endl;
}
