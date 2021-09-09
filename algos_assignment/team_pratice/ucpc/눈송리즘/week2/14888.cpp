#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = -1000000001, MIN = 1000000001;

int n, num[12], op[4]; //op[] : 사용 가능한 연산자 갯수

void dfs(int cnt, int ans, int idx) { //cnt: 사용한 연산자 수, ans : 최종 결과,  idx:num에서 사용할 idx
	if (cnt == n - 1) {
		MAX = max(MAX, ans);
		MIN = min(MIN, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) { //연산자 사용 가능하면
			op[i]--; //한개 사용
			switch (i) {
			case 0: dfs(cnt + 1, ans + num[idx], idx + 1); break;
			case 1: dfs(cnt + 1, ans - num[idx], idx + 1); break;
			case 2: dfs(cnt + 1, ans*num[idx], idx + 1); break;
			case 3: dfs(cnt + 1, ans / num[idx], idx + 1); break;
			}
			op[i]++; //dfs 실행 후 사용횟수+1 (사용 전 상태로 돌리기)
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(0,num[0],1);
	cout << MAX << '\n' << MIN;
}
