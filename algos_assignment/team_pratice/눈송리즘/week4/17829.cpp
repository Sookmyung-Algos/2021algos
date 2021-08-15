#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[1025][1025], tmp[4];

int merge_sort(int a,int b) {
	int idx = 0;
	for (int i = a; i <= a + 1; i++) {
		for (int j = b; j <= b + 1; j++) {
			tmp[idx++] = arr[i][j];
		}
	}
	sort(tmp, tmp + 4);
	return tmp[2];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	}

	while (n > 1) {
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2)
				arr[i / 2][j / 2] = merge_sort(i, j);
		}
		n /= 2;
	}
	cout << arr[0][0];
	return 0;
}
