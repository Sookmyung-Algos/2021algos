#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s == "push") {
			int x; cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1\n";
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "front") {
			if (!q.empty()) cout << q.front() << "\n";
			else cout << "-1\n";
		}
		else {// back인 경우
			if (!q.empty()) cout << q.back() << "\n";
			else cout << "-1\n";
		}
	}
	return 0;
}
