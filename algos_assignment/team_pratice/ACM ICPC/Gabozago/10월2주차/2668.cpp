#include <iostream>
#include <algorithm>
#include<vector>
#include<memory.h>
using namespace std;
int n;
int arr[101];
bool visit[101];
vector<int>v;
void solve(int cur,int num) {
	if (!visit[cur]) {
		visit[cur] = true;
		solve(arr[cur], num);
	}
	else {
		if (cur == num) {
			v.push_back(num);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		solve(i, i); //첫번째 인자 arr[i]가 아닌 i여야 사이클 발생
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
