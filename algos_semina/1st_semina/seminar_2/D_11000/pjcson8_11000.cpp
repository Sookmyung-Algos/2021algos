#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, ans = 1, used = 0;

vector<pair<int, int>> t;

bool cmp(pair<int, int>& a, pair<int, int>& b) { // 시간 빠른 순
	if (a.first == b.first)
		return a.second > b.second; 
	else 
		return a.first < b.first;
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		t.push_back({ a, 0 });	// 시작 시간 push
		t.push_back({ b, 1 });	// 종료 시간 push
	}
	sort(t.begin(), t.end(), cmp); //cmp함수 이용해서 정렬.

	for (int i = 0; i < t.size(); i++) {
		t[i].second ? used-- : used++; //벡터 t의 second값이 0(false)이면 +1, 1(true)이면 -1.
		ans = max(used, ans); //used와 ans중 큰 값 리턴.
	}
	cout << ans;
}
