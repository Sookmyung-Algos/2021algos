#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() > n) //우선순위 큐는 기본적으로 가장 큰 수가 top으로
				pq.pop();
		}
	}
	cout << pq.top();
}
