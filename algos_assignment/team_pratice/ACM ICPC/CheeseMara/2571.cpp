#include<iostream>
#include<vector>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	int a,x,y,height,area,result=0;
	vector<vector<int>>paper(100, vector<int>(100, 0));
	cin >> a;
	while (a--) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				paper[i][j] = 1;
			}
		}
	}
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] != 0) {
				paper[i][j] += paper[i - 1][j];
			}
		}
	}
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			height = 100;
			for (int k = j; k < 100; k++) {
				height = min(height, paper[i][k]);
				if (height == 0) break;
				area = height * (k - j + 1);
				result = max(area, result);
			}
		}
	}
	cout << result << '\n';
	return 0;
}
