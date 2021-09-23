#include <iostream>
#include <queue>
#include <functional> // greater
using namespace std;

bool mark[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		priority_queue<pair<int, int>> max;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;

		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			char ch; int n; cin >> ch >> n;
			if (ch == 'I') {
				mark[i] = true;
				max.push({ n, i }); // 동일한 정수가 삽입될 수 있음 (i로 구분)
				min.push({ n, i });
			}
			else {
				if (n == 1) {
					int sz = max.size();
					for (int j = 0; j < sz; j++) {
						int num = max.top().second;
						if (mark[num]) {
							mark[num] = false;
							max.pop(); 
							break;
						}
						else max.pop();
					}
				}
				else {
					int sz = min.size();
					for (int j = 0; j < sz; j++) {
						int num = min.top().second;
						if (mark[num]) {
							mark[num] = false;
							min.pop();
							break;
						}
						else min.pop();
					}
				}
			}
		}

		while (!max.empty() && !mark[max.top().second]) max.pop();
		while (!min.empty() && !mark[min.top().second]) min.pop();

		if (max.empty() && min.empty()) cout << "EMPTY\n";
		else cout << max.top().first << " " << min.top().first << "\n";
	}
}
