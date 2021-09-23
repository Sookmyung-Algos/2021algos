#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int main() {
	init();

	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int sum;

	while (!q.empty()) {
		int a = q.top();
		q.pop();
		if (q.empty()) break;
		
		int b = q.top();
		q.pop();
		sum = a + b;
		cnt += sum;
		q.push(sum);
	}
	cout << cnt;
	
	
	return 0;
}
