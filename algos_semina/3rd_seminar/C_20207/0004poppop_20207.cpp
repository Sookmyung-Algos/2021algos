#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct sc {
	int start;
	int end;
};

sc cal[1001];
bool chk[1001][366];
int maxH[366];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool operator<(const sc& a, const sc& b) {
	if (a.start == b.start) return a.end > b.end;
	return a.start < b.start;
}

queue <pair<int, int>> startpoint;
queue<pair<int, int>> q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cal[i].start >> cal[i].end;
	}

	sort(cal, cal + n);


	for (int i = 0; i < n; i++) {
		sc now = cal[i];
		int height = 1;

		while (height <= n)
		{
			if (chk[height][now.start])
				height++;
			else break;
		}

		for (int j = now.start; j <= now.end; j++) {
			chk[height][j] = true;
			maxH[j] = max(maxH[j], height);
		}
	}

	int result = 0, maxHeight = 0, l = 0;

	for (int i = 1; i <= 365; i++) {
		if (maxH[i] != 0) {
			l++;
			maxHeight = max(maxH[i], maxHeight);
		}
		else {
			result += maxHeight * l;
			maxHeight = 0; l = 0;
		}
	}

	result += maxHeight * l;

	cout << result << '\n';

	return 0;
}
