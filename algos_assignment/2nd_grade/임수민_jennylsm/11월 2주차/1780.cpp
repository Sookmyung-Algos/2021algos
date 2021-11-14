#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

int n;
int arr[2188][2188];

int c1 = 0, c2 = 0, c3 = 0;

void colorpaper(int row, int col, int num) {
	bool check = true;

	if (num == 1) {
		if (arr[col][row] == 0)
			c1++;
		else if (arr[col][row] == -1)
			c2++;
		else if (arr[col][row] == 1)
			c3++;

		return;
	}
    //모두 같은값인지 확인
	for (int i = 0; i < num;i++) {
		for (int j = 0; j < num;j++) {
			if (arr[col][row] != arr[col + i][row + j]) {
				check = false;	
				break;
			}
		}
	}

	if (check == true) {
		if (arr[col][row] == 0)
			c1++;
		else if (arr[col][row] == -1)
			c2++;
		else
			c3++;
		return;
	}
	else {
		for(int i = 0;i<3;i++)
			for (int j = 0; j < 3;j++) {
				colorpaper(row + i * (num / 3), col + j * (num / 3), num / 3);
			}
	}
}

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> arr[i][j];

	colorpaper(0, 0, n);

	cout << c2 << "\n" << c1 << "\n" << c3 << "\n";

	return 0;	
}
