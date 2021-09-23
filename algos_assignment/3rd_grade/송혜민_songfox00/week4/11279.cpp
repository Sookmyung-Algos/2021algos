#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, less<int>>pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		if (!a && pq.empty()) {
			cout << 0 << '\n';
		}
		else if (!a) {
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			pq.push(a);
		}
	}
	return 0;
}
