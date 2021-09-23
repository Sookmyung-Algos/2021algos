#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int n;
vector<int>v;
vector<int>arr;
bool visit[9];
int ans = 0;
int getSum() {
	int sum = 0;
	for (int i = 0; i < arr.size()-1; i++) {
		sum +=abs( arr[i] - arr[i + 1]);
	}
	return sum;
}
void solve() { //순열
	if (arr.size() == n) {
		ans = max(ans, getSum());
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr.push_back(v[i]);
			solve();
			visit[i] = false;
			arr.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	solve();
	cout << ans;
}
