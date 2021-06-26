#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, m;
int arr[9];
int input[9];
bool visit[9];
void search(int cnt) {
	if (cnt == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && input[i] != tmp) {
			visit[i] = true;
			arr[cnt] = input[i];
			tmp = arr[cnt]; //마지막항 갱신
			search(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	sort(input, input + n + 1);
	search(0);
}
