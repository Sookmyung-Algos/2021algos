// 20207
// 1차원 배열 이용해서 해당 날짜에 일정이 몇 개 있는지

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 366
using namespace std;

int arr[MAX];

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector <pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare); // a가 작은 것 부터 저장

	for (int i = 0; i < N; i++) {
		int a, b;
		a = v[i].first; b = v[i].second;
		for (int j = a; j <= b; j++) {
			arr[j]++;
		}
	}

	int row = 0, col = 0, ans = 0;
	for (int i = 1; i < 366; i++) {
		if (arr[i] != 0) {
			row = max(row, arr[i]);
			col = col + 1;
		}
		else {
			ans = ans + row * col;
			row = 0; col = 0;
		}
	}
	ans = ans + row * col;
	cout << ans;
	return 0;
}
