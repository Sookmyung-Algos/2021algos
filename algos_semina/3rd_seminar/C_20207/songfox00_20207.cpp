#include <iostream>
#include<algorithm>

using namespace std;

int arr[366] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j <= e; j++)
			arr[j]++;
	}

	int width = 0, height = 0, res = 0;
	for (int i = 1; i <= 366; i++) {
		if (arr[i] > 0) {
			width++;
			height = max(height, arr[i]);
		}
		else {
			res += width*height;
			width = 0, height = 0;
		}
	}
	cout << res;
}
