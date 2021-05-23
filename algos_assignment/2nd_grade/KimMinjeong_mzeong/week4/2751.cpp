#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> temp;

void merge(int left, int mid, int right) {
	int left_end, num_elements, tmp_pos;

	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;

	while ((left <= left_end) && (mid <= right)) {
		if (arr[left] <= arr[mid])
			temp[tmp_pos++] = arr[left++];
		else 
			temp[tmp_pos++] = arr[mid++];
	}

	while (left <= left_end) temp[tmp_pos++] = arr[left++];
	while (mid <= right) temp[tmp_pos++] = arr[mid++];

	for (int i = 0; i < num_elements; i++) {
		arr[right] = temp[right];
		right -= 1;
	}
}

void mergesort(int left, int right) {
	int mid;
	if (right > left) {
		mid = (right + left) / 2;
		mergesort(left, mid);
		mergesort(mid+1, right);
		merge(left, mid+1, right);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		temp.push_back(num);
	}
	mergesort(0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
