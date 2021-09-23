#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> v;
int ans[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(make_pair( x, i ));
	}
	sort(v.begin(), v.end());
	ans[0] = 0;
	for (int i = 1; i < N; i++) {
		if (v[i].first != v[i - 1].first) {
			ans[v[i].second] = ans[v[i - 1].second] + 1;
		}
		else ans[v[i].second] = ans[v[i - 1].second];
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	return 0;
}
