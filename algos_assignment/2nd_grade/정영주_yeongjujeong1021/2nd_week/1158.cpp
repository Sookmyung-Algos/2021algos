#include <iostream>
#include <list>

using namespace std;

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;

	list<int> L;

	for (int i = 1; i <= n; i++)
		L.push_back(i);

	cout << '<';
	while (L.size() > 1) {
		if (++cnt == k) {
			cout << L.front() << ", ";
			L.pop_front();
			cnt = 0;
		}
		else {
			L.push_back(L.front());
			L.pop_front();
		}
	}
	cout << L.front() << ">" << '\n';

	return 0;
}
