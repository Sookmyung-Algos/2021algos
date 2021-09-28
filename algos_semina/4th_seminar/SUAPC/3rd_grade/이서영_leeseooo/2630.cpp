#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
int arr[129][129];
int white, blue = 0;
void solve(int x, int y, int size) {
	if (size == 1) { //base case 정복
		if (arr[x][y] == 1)blue++;
		else white++;
		return;
	}
	int check = arr[x][y]; //현재 색종이 색깔
	for (int i = x; i < x + size; i++) { //잘린 색종이가 같은 색인지 판단하기
		for (int j = y; j < y + size; j++) {
			if (check != arr[i][j]) {//같지 않다 => 분할
				solve(x, y, size / 2);// left top
				solve(x, y + size / 2, size / 2); //right top
				solve(x + size / 2, y, size / 2); //left bottom
				solve(x + size / 2, y + size / 2, size / 2); //right bottom
				return;
			}
		}
	}
	if (check == 1) {//같다 => 정복(숫자 세기), 빠져나왔다는거는 색깔 하나의 색종이
		blue++;
	}
	else white++;
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << white << "\n" << blue;
}
