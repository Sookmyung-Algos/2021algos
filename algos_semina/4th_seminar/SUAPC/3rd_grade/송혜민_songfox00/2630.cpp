#include<iostream>

using namespace std;

int n, arr[129][129];

int b = 0, w = 0;
void solve(int x, int y, int size) {

	if (size == 1) {
		if (arr[x][y] == 1)
			b++;
		else
			w++;
		return;
	}

	/*잘린 색종이가 같은 색인지 판단하기*/
	int check = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check !=arr[i][j]) {
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	
	if (check == 1)
		b++;
	else
		w++;
	return;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i= 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);

	cout << w << '\n' << b << '\n';
	return 0;
}
