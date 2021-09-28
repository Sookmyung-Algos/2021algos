#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> clas;

priority_queue<int, vector<int>, greater<int>> room;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first < b.first) {
		return 1;
	}
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return 0;
}

int main() {

	int n, end_time;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;

		cin >> a >> b;

		clas.push_back(make_pair(a, b));
	}

	sort(clas.begin(), clas.end(), cmp);

	for (int i = 0; i < n; i++) {

		end_time = clas[i].second;

		if (!room.empty() && room.top() <= clas[i].first) {
			room.pop();
		}

		room.push(end_time);
	}

	cout << room.size();

}
