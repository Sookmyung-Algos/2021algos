#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

vector <int> v;
int arr[1000001];
void bs(int n) {
	int start = 0, end = v.size() - 1;
	int mid;
	int ret = 21e6;
	while (start <= end) {
		mid = (start + end) / 2;
		int h = v[mid];
		if (h >= n) {
			if (ret > mid) ret = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	v[ret] = n;
}
int main() {
	init();

	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i]) v.push_back(arr[i]);
		else bs(arr[i]);

	}
	cout << v.size();
	return 0;
}
