#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {

	vector<int> v;
	int N, M, B, area, time = 128000000, height = -1;
	cin >> N >> M >> B;

	area = N*M;

	int n;
	for (int i = 0; i < area; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.rbegin(), v.rend());

	int cnt, err, inven;
	for (int i = 0; i < 257; i++) {// 만들고자 하는 높이
		cnt = 0;
		err = 0;
		inven = B;
		for (int j = 0; j < area; j++) {
			if (i - v[j] > 0) {// 블록 추가
				cnt += (i - v[j]);// 시간
				inven -= (i - v[j]);
				if (inven < 0) {
					err = 1;
					break;
				}

			}
			else if (i - v[j] < 0) {// 블록 제거
				cnt += (i - v[j]) * -2;// 시간
				inven += (i - v[j]) * -1;
			}
		}
		if (cnt <= time && height < i && err != 1) {
			time = cnt;
			height = i;
		}
	}
	cout << time << ' ' << height << '\n';
}
