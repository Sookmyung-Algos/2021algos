#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, x, mark = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		d.push_back({ i + 1, x });
	}

	while (1) {
		cout << d.front().first << ' ';
		mark = d.front().second;
		d.erase(d.begin());

		if (d.empty()) break;

		if (mark > 0) {
			for (int i = 0; i < mark - 1; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else { // mark < 0
			for (int i = mark; i < 0; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}

	cout << '\n';

	return 0;
}
