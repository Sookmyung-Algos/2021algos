#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define max(a,b) (a>b?a:b)

typedef pair<int,int> P;

bool cmp(P a, P b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
	
}
struct compare{
	bool operator()(P a, P b) {
		return a.second > b.second;
	}
};

void print_queue(priority_queue<P, vector<P>, compare> q) {
	while (!q.empty()) {
		cout << q.top().first << "," << q.top().second << " " ;
		q.pop();
	}
	cout << endl;
}

int main() {
	int n;
	scanf("%d", &n);
	pair<int, int> day[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &day[i].first, &day[i].second);
	}
	sort(day, day + n, cmp);
	priority_queue<P, vector<P>, compare> q;
	q.push(day[0]);
	int first = day[0].first, ans = 0, height = 1, last = day[0].second;
	for (int i = 1; i < n; ++i) {
		if (q.top().second < day[i].first) {
			q.pop();
			if (last + 1 < day[i].first) {
				while (!q.empty()) q.pop();
				ans += (last - first + 1) *  height; height = 0;
				first = day[i].first;
			}
			q.push(day[i]);
			last = max(last, day[i].second);
			height = max(height, q.size());
			continue;
		}
		q.push(day[i]);
		last = max(last, day[i].second);
		height = max(height, q.size());
	}
	if (!q.empty()) {
		ans += (last - first + 1) * height;
	}
	printf("%d", ans);
	return 0;
}
