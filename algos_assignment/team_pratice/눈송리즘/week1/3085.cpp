#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

char arr[51][51];
int main() {
	int n, max = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	//처음
	for (int i = 0;i < n;i++) {
		int cnt1=0, cnt2 = 0;
		for (int j = 1;j < n;j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				cnt1++;
			}
			else {
				if (cnt1 > max) max = cnt1;
				cnt1 = 0;
			}
			if (arr[j][i] == arr[j-1][i]) {
				cnt2++;
			}
			else {
				if (cnt2 > max) max = cnt2;
				cnt2 = 0;
			}
		}
		if (cnt1 > max) max = cnt1;
		if (cnt2 > max) max = cnt2;
	}
	if (max == n) {
		cout << n;
		return 0;
	}
	//교환
	for (int k = 0;k < n;k++) {
		for (int m = 1;m < n;m++) {
			swap(arr[k][m],arr[k][m - 1]);
			for (int i = 0;i < n;i++) {
				int cnt1 = 0, cnt2 = 0;
				for (int j = 1;j < n;j++) {
					if (arr[i][j] == arr[i][j - 1]) {
						cnt1++;
					}
					else {
						if (cnt1 > max) max = cnt1;
						cnt1 = 0;
					}
					if (arr[j][i] == arr[j - 1][i]) {
						cnt2++;
					}
					else {
						if (cnt2 > max) max = cnt2;
						cnt2 = 0;
					}
				}
				if (cnt1 > max) max = cnt1;
				if (cnt2 > max) max = cnt2;
			}
			swap(arr[k][m], arr[k][m - 1]);

			swap(arr[m][k],arr[m - 1][k]);
			for (int i = 0;i < n;i++) {
				int cnt1 = 0, cnt2 = 0;
				for (int j = 1;j < n;j++) {
					if (arr[i][j] == arr[i][j - 1]) {
						cnt1++;
					}
					else {
						if (cnt1 > max) max = cnt1;
						cnt1 = 0;
					}
					if (arr[j][i] == arr[j - 1][i]) {
						cnt2++;
					}
					else {
						if (cnt2 > max) max = cnt2;
						cnt2 = 0;
					}
				}
				if (cnt1 > max) max = cnt1;
				if (cnt2 > max) max = cnt2;
			}
			swap(arr[m][k], arr[m - 1][k]);
		}
	}
	if (max == 0) cout << 0;
	else cout << max+1;
	return 0;
}
