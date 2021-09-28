#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional> //greater 사용위한 헤더추가

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int> > pq;
	//우선순위 큐: 들어간 순서 상관없이 우선순위 높은 데이터가 선출
	//greater 내림차순
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);

	pq.push(p[0].second);

	for (int i = 1; i < n; ++i) {
		if (pq.top() <= p[i].first) {//넣을 수 있다면
			pq.pop();
			pq.push(p[i].second);//pq갱신
		}
		else {//넣을 수 없다면
			pq.push(p[i].second);//그냥 넣기->강의실 추가
		}
	}

	cout << pq.size();

	return 0;
}
