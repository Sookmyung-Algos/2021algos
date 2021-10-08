#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,red[1001],green[1001],blue[1001];
	int r=0, g=0, b=0; // 현재까지의 최솟값 저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> red[i] >> green[i] >> blue[i];
		if (i > 0) {
			// 현재 집을 빨강으로
			int n_r = (g < b) ? g + red[i] : b + red[i];
			// 현재 집을 초록으로
			int n_g = (r < b) ? r + green[i] : b + green[i];
			// 현재 집을 파랑으로
			int n_b = (g < r) ? g + blue[i] : r + blue[i];

			// 현재 집까지 칠했을 때의 비용 최솟값을 새로 저장
			r = n_r;
			g = n_g;
			b = n_b;
		}
		else { // i=0
			r = red[i];
			g = green[i];
			b = blue[i];
		}
	}
	int result = min(min(r, g),b); // 비용의 최솟값 result에 저장

	cout << result << endl;
	return 0;


}
