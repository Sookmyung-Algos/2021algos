#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	int x1, x2, y1, y2;
	int pcnt = 0, ncnt = 0;

	vector <pair<int, int>> coor;

	cin >> a >> b >> c;
	cin >> x1 >> x2 >> y1 >> y2;

	coor.push_back({ x1, y1 });
	coor.push_back({ x1, y2 });
	coor.push_back({ x2, y1 });
	coor.push_back({ x2, y2 });

	for (int i = 0; i < coor.size(); i++) {
		if (coor[i].first * a + coor[i].second * b + c >= 0) pcnt++;
		if (coor[i].first * a + coor[i].second * b + c <= 0) ncnt++;
	}

	if (pcnt == 4 || ncnt == 4)
		cout << "Lucky";
	else
		cout << "Poor";

	return 0;
}
