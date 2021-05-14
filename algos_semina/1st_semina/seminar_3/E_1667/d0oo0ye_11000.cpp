#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
int num = 1, use = 0;
vector<pair<int, int>> t;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) 
		return a.second > b.second;
	else 
		return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);

		t.push_back({ a, 0 });
		t.push_back({ b, 1 });
	}

	sort(t.begin(), t.end(), compare);

	for (int i = 0; i < t.size(); i++) {
		t[i].second ? use-- : use++;
		num = max(use, num);
	}
	printf("%d", num);
}
