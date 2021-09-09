#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int l, w, h, n, res=0;
vector<pair<int,int>>v;
bool check = true;	//채울 수 있는지 확인

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first > b.first)
		return true;
	return false;
}

void solve(int l, int w, int h) {
	if (l == 0 || w == 0 || h == 0)	//남은 자리가 없을 때
		return;

	for(int i = 0; i < n; i++) {
		if (v[i].second > 0 && l >= v[i].first && w >= v[i].first && h >= v[i].first) {	//박스의 크기보다 큐브의 크기가 작을 때
			v[i].second--;	//하나 채우기
			res++;
			solve(l, w, h - v[i].first);
			solve(v[i].first, w - v[i].first, v[i].first);
			solve(l-v[i].first, w, v[i].first);
			return;
		}
	}
	check = false;
}

int main() {
	cin >> l >> w >> h >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ pow(2,a), b });
	}

	sort(v.begin(), v.end(), cmp);	//큰거부터

	solve(l, w, h);

	if (check)
		cout << res;
	else
		cout << -1;
	return 0;
}
