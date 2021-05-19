#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, d, w, total;
int work_day[1001] = { 1, 0, }; // 배열 0으로 초기화

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	total = 0;

	cin >> n; // 과제 개수 입력

	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back({ w,d }); // 점수, 기한 순
	}
	sort(v.begin(), v.end()); // 점수 기준으로 정렬(작은 순서부터)

	int end;
	for (int i = n - 1; i >= 0; i--) {
		end = v[i].second;
		while (end >= 1) {
			if (work_day[end] == 0) {
				work_day[end] = v[i].first;
				break;
			}
			else {
				end = end - 1;
			}
		}
	}

	for (int i = 1; i < 1000; i++) {
		total = total + work_day[i];
	}

	cout << total << "\n";
	return 0;
}
