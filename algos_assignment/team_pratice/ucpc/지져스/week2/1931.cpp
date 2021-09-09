#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// second 기준 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	int last=0; // 끝나는 시간
	int room = 0;
	cin >> N; // 회의 개수

	vector <pair<int, int>> v; 

	// 입력
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	// second 기준 정렬
	sort(v.begin(), v.end(), cmp);

	// 회의실 많게
	// 끝나는 시간이 낮은 수로 고르기
	last = v[0].second;
	room = 1;

	for (int i = 1; i< N ; i++) {
		if (last <= v[i].first) {
			last = v[i].second;
			room++;
		}
	}

	cout << room;
	return 0;
}

