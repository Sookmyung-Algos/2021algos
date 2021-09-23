#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m;
int cnt = 0;
vector<int>v;
vector<int>vec;
void solve(int c) {
	if (m <= 0)return;
	else {
		c -= 10;
		cnt++;
		m--;
		if (c > 10)solve(c);
		else if (c == 10)cnt++;
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 10)cnt++;
		else if (a < 10)continue;
		else v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	if (v.size() == 0) {
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {//10의 배수만 먼저 처리(1번 커팅으로 2개가 나오므로)
		if (m <= 0)break;
		else if (v[i] % 10 == 0)solve(v[i]);//10의 배수 중에서도 크기가 작은것부터 선행되어야함
		else vec.push_back(v[i]);
	}
	for (int i = 0; i < vec.size(); i++) {
		solve(vec[i]); //10의 배수가 아닌 것들만 따로
	}
	cout << cnt;
}
