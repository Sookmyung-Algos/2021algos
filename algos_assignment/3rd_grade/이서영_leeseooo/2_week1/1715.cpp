#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>>pq;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int sum = 0;
	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == n - 1)break;
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		sum += a + b;
		pq.push(a + b);
		cnt++;
	}
	cout << sum;
}
