#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> P;
#define MIN 2147483647

int main() {
	int n;
	vector<P> arr;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i += 2) {
		int L, H, R;
		scanf("%d%d%d", &L, &H, &R);
		arr.push_back({ {L, H}, {1, R} });
		arr.push_back({ {R, H}, {0, L} });
	}
	sort(arr.begin(), arr.end());
	set<pair<int, int>, greater<>> m;
	m.insert({ 0,0 });
	vector<P>::iterator it;
	for (it = arr.begin(); it != arr.end(); it++) {
		int cur = it->first.first, h = it->first.second;
		int max_s = 0, min_e = MIN, prev = m.begin()->first;
		auto j = it;
		for (; j != arr.end(); j++) {
			if (cur != j->first.first) break;
			if (j->second.first) {
				max_s = max_s > j->first.second ? max_s : j->first.second;
				m.insert({ j->first.second, j->first.first });
			}
			else {
				min_e = min_e < j->first.second ? min_e : j->first.second;
				auto tp = m.find({ j->first.second, j->second.second });
				m.erase(tp);
			}
		}
		if (max_s) { if (prev < max_s) printf("%d %d ", cur, max_s); }
		if (min_e < MIN) { if (min_e > m.begin()->first) printf("%d %d ", cur, m.begin()->first); }
		it = j; it--; if (it == arr.end()) break;
		// if (it->second.first) {
		// 	if (m.begin()->first < it->first.second)
		// 		printf("%d %d ", it->first.first, it->first.second);
		// 	m.insert({ it->first.second, it->first.first });
		// }
		// else {
		// 	auto iter = m.find({ it->first.second, it->second.second });
		// 	int tmp_max = iter->first;
		// 	m.erase(iter);
		// 	if (tmp_max > m.begin()->first)
		// 		printf("%d %d ", it->first.first, m.begin()->first);
		// }
	}
	return 0;
}
