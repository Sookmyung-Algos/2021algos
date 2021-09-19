#include <iostream>
#include <deque>
using namespace std;

int n, k, m;
deque<int> d;

int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)	d.push_back(i);

	int cnt = 0; //m개 지울 때마다 방향 뒤집기 위함
	bool flip = 0;
	while (d.size() > 1) {
		if (flip == 0) { //순방향
			for (int i = 0; i < k - 1; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		else{ //역방향
			for (int i = 0; i < k - 1; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		cnt++;
		if (cnt == m) {
			cnt = 0;
			flip = !flip; //방향전환
		}
	}
	cout << d.back();
	return 0;
}
