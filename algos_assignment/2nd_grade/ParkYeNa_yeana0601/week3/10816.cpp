#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lower_bound(int arr[], int target, int size) { //target이 존재하기 시작하는 인덱스 구하기
	int start = 0, end = size - 1;
	int mid;
	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int upper_bound(int arr[], int target, int size) { //target보다 크기 시작한 인덱스 구하기
	int start = 0, end = size - 1;
	int mid;
	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {
	vector <int>v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " "; //upper_bound-lower_bound는 target 개수

	}
}
