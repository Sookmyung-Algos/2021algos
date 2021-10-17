#include <iostream>
using namespace std;
int sleep[5010];
int student[5010];
int presum[5010];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k, q, m, s, e, check;

	cin >> n >> k >> q >> m;
	for (int i = 3; i < n+3; i++)  // 출석체크 안한 상태가 1
		student[i] = 1;
	
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		sleep[a] = 1; // 졸고 있으면 sleep[i]가 1
	}
	
	for (int i = 0; i < q; i++) {
		cin >> check; // 지환이에게 번호 받는 사람
		if (sleep[check] != 1) { // 번호 받은 사람이 졸고 있지 않으면
			int a = 2;
			for (int j = check; j < n+3; j = check * a++) { // 출석 체크하는 과정
				
				if (sleep[j] != 1 && student[j] == 1) { // 졸고 있지 않으면+아직 체크 안했으면
					student[j] = 0; // 출석체크
				}
			}
		}
	}
	for (int i = 3; i < n + 3; i++) {
		presum[i] = presum[i - 1] + student[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << presum[e] - presum[s - 1] << "\n";
	}
}
