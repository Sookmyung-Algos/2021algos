#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) { // 만약, 시작 시간이 같다면 종료 시간이 가장 빠른 순서대로 정렬하기 위함
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<int, vector<int>, greater<int>> tq;

int main() {
	int n, s, t;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		pq.push({s, t});
	}

	while (!pq.empty()) {
		tie(s, t) = pq.top(); pq.pop();
		if (tq.empty()) {
			tq.push(t); // 현재 강의실 0개이므로 강의실 생성해 해당 수업 할당
		}
		else { // 비어있지 않으면, 현재 강의실 중 종료 시간이 가장 이른 강의실의 종료시간과 현재 수업의 시작 시간을 비교
			if (s >= tq.top()) { // 기존 수업과 겹치지 않음
				tq.pop();
				tq.push(t); // 종료시간 갱신
			}
			else { // 기존 수업과 겹침
				tq.push(t); // 새로운 강의실 생성해 해당 수업 할당
			}
		}
	}
	cout << tq.size(); // 강의실의 개수 출력
	return 0;
}
