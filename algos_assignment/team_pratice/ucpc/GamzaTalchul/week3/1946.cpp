#include <iostream>
#include <algorithm>
#include <vector>
/*#include <deque>
deque <char> d;*/
using namespace std;
vector <pair<int, int>> v;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, y;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int ans = 0, rank = 123456789;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end()); //pair일 때는 first값을 기준으로 sort함
		for (int i = 0; i < n; i++) {
			if (rank > v[i].second) {
				rank = v[i].second;
				ans++;
			}
		}
		cout << ans << "\n";
		v.clear();
	}
}
