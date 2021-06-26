#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	vector <int> mi, pl;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num < 0) mi.push_back(num*-1);
		else pl.push_back(num);
	}
	if(!mi.empty()) sort(mi.begin(), mi.end(),cmp);
	if(!pl.empty()) sort(pl.begin(), pl.end(),cmp);
	
	
	for (int i = 0; i < mi.size(); i += m) {
		ans += mi[i] * 2;
	}
	for (int i = 0; i < pl.size(); i += m) {
		ans += pl[i] * 2;
	}
	
	if (mi.empty()) ans -= pl[0];
	if (pl.empty()) ans -= mi[0];

	if (!mi.empty() && !pl.empty()) {
		if (mi[0] > pl[0]) ans -= mi[0];
		else ans -= pl[0];
	}
	cout << ans;

}
