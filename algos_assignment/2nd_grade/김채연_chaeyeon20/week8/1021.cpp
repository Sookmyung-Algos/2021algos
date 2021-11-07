#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	queue<int>q;
	int n, m;
	int index = 0;
	int cnt = 0;
	int num = 0;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for(int i=0;i<m;i++){
		cin >> num;

		for (int i = 0; i <= dq.size(); ++i) { //찾고자 하는 원소가 덱에 어디에 있는지 판별
			if (num == dq[i]) {
				index = i;
				break;
			}
		}

		if (index < dq.size() - index) {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++cnt;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++cnt;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

	}
	cout << cnt;
}
