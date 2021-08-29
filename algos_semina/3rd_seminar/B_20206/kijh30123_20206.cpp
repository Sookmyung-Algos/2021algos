#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	int x1, x2, y1, y2;

	vector<pair<int, int>> xy_point;
	cin >> x1 >> x2 >> y1 >> y2;
	xy_point.push_back({ x1,y1 });
	xy_point.push_back({ x1,y2 });
	xy_point.push_back({ x2,y1 });
	xy_point.push_back({ x2,y2 });

	int check[2] = { 0,0 };
	
	for (int i = 0; i < xy_point.size(); i++)
	{
		if (xy_point[i].first * a + xy_point[i].second * b <= -c)
			check[0]++; //방정식이라는 점을 이용하여 지나가는지 확인
		if (xy_point[i].first * a + xy_point[i].second * b >= -c)
			check[1]++;
	}
	if (check[0] == 4 || check[1] == 4)
		cout << "Lucky";
	else
		cout << "Poor";

	return 0;
}
