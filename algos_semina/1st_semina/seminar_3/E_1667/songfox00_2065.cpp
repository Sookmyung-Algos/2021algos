#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<> >pq;

	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++){
		int a;
		cin >> a;
		pq.push(-a);
		if (pq.size() > n)
			pq.pop();
		}
	}

	cout << -pq.top();
	return 0;
}
