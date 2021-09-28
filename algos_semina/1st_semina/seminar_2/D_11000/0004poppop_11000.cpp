#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	pair<int, int> lecture[200001];
	priority_queue<int, vector<int>, greater < int >> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lecture[i].first >> lecture[i].second;
	} // 시작하는 시간 끝나는 시간 pair로 입력받기

	sort(lecture, lecture + n); // 시작시간 기준 정렬

	pq.push(lecture[0].second); // 우선순위 큐 pq에 첫 강의의 끝나는 시간 넣기

	for (int i = 1; i < n; i++) {
		if (pq.top() <= lecture[i].first) { // 현재 강의 끝나는 시간이 다음 강의 시작 시간보다 먼저일 때
			pq.pop();
			pq.push(lecture[i].second);
		} // 강의실이 추가로 필요하지 않으므로 pop한 뒤 다음 강의 끝나는 시간 push
		else {
			pq.push(lecture[i].second);
		} // 강의실이 추가로 필요하므로 pop하지 않고 push
	}
	cout << pq.size(); // pq의 크기 = 강의실의 개수
	return 0;
}
