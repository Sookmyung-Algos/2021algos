#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


vector <pair<int, int>> arr;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
int main() {
	init();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));

	}
	sort(arr.begin(), arr.end());
	temp.push(make_pair(arr[0].second,arr[1].first));

	for (int i = 1; i < arr.size(); i++) {
		if (temp.top().first > arr[i].first) temp.push(make_pair(arr[i].second,arr[i].first));
		else {
			temp.pop();
			temp.push(make_pair(arr[i].second, arr[i].first));
		}
	}


	cout << temp.size();
	return 0;
}
