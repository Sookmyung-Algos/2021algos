#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int num;
queue <int> q;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp[10];
		cin >> temp;
		if (!strcmp(temp, "push")) {
			cin >> num;
			q.push(num);
		}
		if (!strcmp(temp, "pop")) {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if (!strcmp(temp, "front")) {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else cout << q.front() << "\n";
		}
		if (!strcmp(temp, "back")) {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else cout << q.back() << "\n";
		}
		if (!strcmp(temp, "empty")) {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		if (!strcmp(temp, "size")) {
			cout << q.size() << "\n";
		}
	}
}
