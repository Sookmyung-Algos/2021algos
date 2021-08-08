#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector <pair< int, int >> v;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int ans1 = 0, ans2 = 0;
	int a, b, c;
	cin >> a >> b >> c;
	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	v.push_back(make_pair(x1, y1));
	v.push_back(make_pair(x1, y2));
	v.push_back(make_pair(x2, y1));
	v.push_back(make_pair(x2, y2));
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first*a + v[i].second*b <= -1*c)  //모든 모서리가 직선보다 클 때
			ans1++;
		if (v[i].first*a + v[i].second*b >= -1*c)  //위와 반대
			ans2++;
	}
	if (ans1 == 4 || ans2 == 4)
		cout << "Lucky";
	else
		cout << "Poor";
}
