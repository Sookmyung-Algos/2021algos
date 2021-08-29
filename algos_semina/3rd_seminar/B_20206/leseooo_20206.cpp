#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	int s1 = 0, s2 = 0;
	vector<pair<int, int>> xy;
	xy.push_back({ x1, y1 });
	xy.push_back({ x2, y1 });
	xy.push_back({ x1, y2 });
	xy.push_back({ x2, y2 });
	for (int i = 0; i < 4; i++) {
		if (xy[i].first * a + xy[i].second * b <= -c)
			s1++;
		if (xy[i].first * a + xy[i].second * b >= -c)
			s2++;
	}
	if (s1 == 4 or s2 == 4) {
		cout << "Lucky";
	}
	else
		cout << "Poor";
}
