#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int arr[100000];
queue <int> q;
queue<int>result;
int main() {
	init();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	int ti = 1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (ti % k == 0) {
			result.push(a);
		}
		else {
			q.push(a);
		}
		ti++;
	}
	
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << result.front();
		else cout <<result.front() << ", ";
		result.pop();
	}
	cout << ">";
	return 0;
}
