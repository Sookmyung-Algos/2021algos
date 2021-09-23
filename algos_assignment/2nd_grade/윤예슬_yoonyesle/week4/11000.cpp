#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, bool> p;

bool comp(p a, p b) {
	if (a.first == b.first) {
		if (a.second && b.second)
			return false;
		return b.second;
	}
	return a.first < b.first;
}

int main() {
	int n;
	vector<p> in;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int start, end;
		scanf("%d%d", &start, &end);
		in.push_back({start, true});
		in.push_back({end, false});
	}
	sort(in.begin(), in.end(), comp);
	int ans = 0, classes = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (in[i].second)
			++classes;
		else
			--classes;
		ans = ans > classes ? ans : classes;
	}
	printf("%d", ans);
	return 0;
}
