#include <iostream> 
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	for (int j = 0;j < v.size();j++) {
		int start = v[j].first;
		int finish = v[j].second;

		if (pq.empty())
			pq.push(finish);
		else {
			//같은 강의실에서 듣는다
			if (start >= pq.top()) {
				pq.pop();
				pq.push(finish);
			}
			//새로운 강의실을 추가한다
			else
				pq.push(finish);
		}
	}
	cout << pq.size() << "\n";

}
