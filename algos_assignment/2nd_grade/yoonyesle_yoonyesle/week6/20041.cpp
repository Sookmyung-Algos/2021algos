#include <iostream>
using namespace std;

int main() {
	int n;
	pair<int,int> dd, cops[500'001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &cops[i].first, &cops[i].second);
	scanf("%d%d", &dd.first, &dd.second);
	bool dir[4] = {false};
	for (int i = 0; i < n; ++i) {
		if (cops[i].first == dd.first && cops[i].second == dd.second) {
			dir[0] = dir[1] = dir[2] = dir[3] = true;
			break;
		}
		if (cops[i].first < dd.first
		&& dd.first - cops[i].first >= abs(dd.second - cops[i].second))
			dir[0] = true;
		else if (cops[i].first > dd.first
		&& cops[i].first - dd.first >= abs(cops[i].second - dd.second))
			dir[1] = true;
		if (cops[i].second < dd.second
		&& dd.second - cops[i].second >= abs(dd.first - cops[i].first))
			dir[2] = true;
		else if (cops[i].second > dd.second
		&& cops[i].second - dd.second >= abs(cops[i].first - dd.first))
			dir[3] = true;
	}
	if (!dir[0] || !dir[1] || !dir[2] || !dir[3])
		printf("YES");
	else
		printf("NO");
	return 0;
}
