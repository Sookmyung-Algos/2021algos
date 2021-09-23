#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, k;

int solve(vector<int> v, int N, int K)
{
	// 투포인터
	int s = 0, e = N - 1, sum = 0, cnt = 0;
	int minD = 200000001;
	while (s < e) {
		sum = v[s] + v[e];
		if (sum == K) {
			s++; e--;
		}
		else if (sum < K) s++;
		else e--;

		// K와 sum의 차가 현재 minD변수보다 작으면 값을 바꿔주고,
		// 새로 카운트를 시작하는 것이므로 cnt값을 1로 지정한다.
		if (abs(K - sum) < minD) {
			minD = abs(K - sum);
			cnt = 1;
		}
		// 같은 경우에는 cnt 값을 하나 키워준다.
		else if (abs(K - sum) == minD) cnt++;
	}
	return cnt;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n >> k;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cout << solve(v, n, k) << "\n";
		v.clear();
	}
	return 0;
}
