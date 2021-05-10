#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> coor;

int main() {

	int n;

	cin >> n;

	for(int i = 0; i < n; i++) {
		int x, y;

		cin >> x >> y;

		coor.push_back(make_pair(x, y));
	}

	sort(coor.begin(), coor.end());

	for (int i = 0; i < n; i++) {
		cout << coor[i].first << " " << coor[i].second << "\n";
	}

}
