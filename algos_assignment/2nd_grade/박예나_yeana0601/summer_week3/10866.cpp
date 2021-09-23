#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int n;
int num;
deque <int> dq;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp[100];
		cin >> temp;
		if (!strcmp(temp, "push_front")) {
			cin >> num;
			dq.push_front(num);
		}
		if (!strcmp(temp, "push_back")) {
			cin >> num;
			dq.push_back(num);
		}
		if (!strcmp(temp, "pop_front")) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if (!strcmp(temp, "pop_back")) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if (!strcmp(temp, "front")) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else cout << dq.front() << "\n";
		}
		if (!strcmp(temp, "back")) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else cout << dq.back() << "\n";
		}
		if (!strcmp(temp, "empty")) {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		if (!strcmp(temp, "size")) {
			cout << dq.size() << "\n";
		}
	}
}
