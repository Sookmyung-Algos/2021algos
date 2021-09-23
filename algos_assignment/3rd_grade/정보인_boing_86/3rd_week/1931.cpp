#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int, int>> v;

int main() {
	int n, start, end;
	int count = 0;
	int finish = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end, start });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (finish <= v[i].second) {
			finish = v[i].first;
			count++;
		}
	}
	cout << count;
}
