// S3_2630 색종이 만들기.cpp

#include <iostream>
#include <vector>
#define MAX 128
using namespace std;

int N;
int arr[MAX][MAX];
int blue, white;

void check(int x, int y, int size) {

	if (size == 1) {
		if (arr[x][y] == 0) white++;
		else if (arr[x][y] == 1) blue++;
		return;
	}
	
	for (int i = x; i < x+size; i++) { // 0 <= < 2
		for (int j = y; j < y+size; j++) { // 0<= < 2
			if (arr[x][y] != arr[i][j]) { 
				check(x, y, size / 2); // (0,0,1)
				check(x, y + size / 2, size / 2); //(0,1,1)
				check(x + size / 2, y, size / 2); // (1,0,1)
				check(x + size / 2, y + size / 2, size / 2); // (1,1,1)
				return;
			}
		}
	}
	if (arr[x][y] == 0) white++;
	else if (arr[x][y] == 1) blue++;
	return;
}

int main() {

	cin >> N; // N=6 -> 4-> 2 -> 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	check(0, 0, N);
	cout << white << "\n" << blue;

	return 0;
}
