#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct sc {
	int start;
	int end;
};

bool operator < (const sc& a, const sc& b) {
	if (a.start == b.start) return a.end > b.end;
	return a.start < b.start;
}

sc sche[1000];
bool check[1005][370];
int maxH[370];

queue <pair<int, int>> sPoint;
queue<pair<int, int>> q;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sche[i].start >> sche[i].end;
	}

	sort(sche, sche + n);

	for (int i = 0; i < n; i++) {
		sc now = sche[i];
		int height = 1;

		while (height <= n)
		{
			if (check[height][now.start])
				height++;
			else break;
		}

		for (int j = now.start; j <= now.end; j++) {
			check[height][j] = true;
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
