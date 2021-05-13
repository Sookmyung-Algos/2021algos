#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	queue <int> q;

	cin >> n >> m;
	cout << "<";
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) { // q가 비어있지 않을 때
		for (int j = 0; j < m - 1; j++) {
			q.push(q.front());
			q.pop();
		} // m번째 원소를 출력하고 제거하기 위한 사전 작업, m번째 원소가 가장 앞에 오게 함
		cout << q.front(); // m번째 원소 출력
		q.pop(); // m번째 원소 제거
		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}
