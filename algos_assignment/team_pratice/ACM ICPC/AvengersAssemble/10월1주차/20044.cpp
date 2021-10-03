#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	int n;
	cin >> n;
	int num[10001];
	for (int i = 0;i < 2*n;i++) {
		cin >> num[i];
	}
	sort(num, num + 2*n);
	for (int i = 0;i < n;i++) {
		pq.push(-(num[i] + num[2 * n - 1-i]));
	}
	
	cout<< -pq.top();
	return 0;
}
