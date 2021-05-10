#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

priority_queue<pair<int, int>> pq; // 끝나는 시간, 강의실 번호
priority_queue<int> room; // 빈 강의실

int main() {
	int class_num;
	cin >> class_num;
	int ans = 0;

	vector<pair<int, int>> vec(class_num); // 벡터 생성
	

	for (int i = 0; i < class_num; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end());

	// 강의실 배정
	for (int i = 0; i < class_num; i++) {
		int front = vec[i].first;
		int end = vec[i].second;

		while (!pq.empty()) {
			//강의실 시작 시간이 다른 강의실의 끝나는 시간보다 크면 뽑기
			if (-pq.top().first > front) break;
			room.push(pq.top().second);
			pq.pop();
		}

		// 빈 강의실 있으면 넣기
		if (!room.empty()) {
			pq.push({ -end, room.top() });
			room.pop();
		}

		// 빈 강의실이 없으면 추가
		else {
			++ans;
			pq.push({ -end, ans });
		}
	}

	cout << ans << '\n';
	return 0;
}
