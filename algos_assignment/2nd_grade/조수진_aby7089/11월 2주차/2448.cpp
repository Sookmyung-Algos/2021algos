#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N;
char a[3100][6200];

void draw(int y, int x) {  //기본 구조
	a[y][x] = '*';
	a[y + 1][x - 1] = '*';
	a[y + 1][x + 1] = '*';
	for (int i = 0; i < 5; i++)
		a[y + 2][x - 2 + i] = '*';
}

void div(int y, int x, int n) {  
	if (n==3) {
		draw(y, x);
		return;
	}
	div(y, x, n / 2);  //첫번째 삼각형 꼭짓점
	div(y + n / 2, x - n / 2, n / 2);  //두번째 꼭짓점
	div(y + n / 2, x + n / 2, n / 2);  //세번째 꼭짓점
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {  //미리 공백 넣기
		for (int j = 0; j < N * 2 - 1; j++)
			a[i][j] = ' ';
	}
	div(0, N - 1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++)
			cout << a[i][j];
		cout << "\n";
	}
}
