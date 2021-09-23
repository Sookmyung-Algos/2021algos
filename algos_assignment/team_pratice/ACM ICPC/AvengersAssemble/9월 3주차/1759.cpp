#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
char c[20];
char arr[20];
int password[2] = { 0, };


void backtracking(int pre, int cnt);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> c[i];
	}
	sort(c, c + m);
	backtracking(-1, 0);
	return 0;
}

void backtracking(int pre, int cnt) {
	if (cnt == n) {
		if (password[0] >= 1 && password[1] >= 2) {
			for (int i = 0;i < n;i++) {
				cout << arr[i];
			}
			cout << "\n";
		}
		return;
	}
	if (pre >= m-1) {
		return;
	}

	for (int i = pre + 1;i < m;i++) {
		arr[cnt] = c[i];
		if (arr[cnt] == 'a' || arr[cnt] == 'e' || arr[cnt] == 'i' || arr[cnt] == 'o' || arr[cnt] == 'u') {
			password[0]++;
			backtracking(i, cnt + 1);
			password[0]--;
		}
		else {
			password[1]++;
			backtracking(i, cnt + 1);
			password[1]--;
		}
	}
}
