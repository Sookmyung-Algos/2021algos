#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> v;
priority_queue <int, vector<int>, greater<int>> q;  //우선순위 큐

int main() {
	int n, x, y;
	int time;
	cin >> n;
	for (int i = 0; i < n; i++) {  //벡터에 시간 값 삽입을 n번 반복
		cin >> x >> y;
		v.push_back(make_pair(x, y));  
	}
	sort(v.begin(), v.end());  //정렬
	for (int i = 0; i < n; i++) {
		if (!q.empty()&&q.top() <= v[i].first) //강의 끝나는 시간이 다음 강의 시작 시간보다 작거나 같을 때
			q.pop();
		q.push(v[i].second);	
	}
	cout << q.size()<<'\n';
}
