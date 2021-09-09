#include <iostream>
#include <algorithm>
#include <vector>
//*****미완성 코드. 코드 구조 및 이해 부분은 사진으로 업로드함. 입력에서 막힘ㅠㅠㅠㅠ*****

using namespace std;

vector<vector<int>> sch_stk;
vector<int> sch;
vector<int> stk;

int main() {
	int t, n, m, k, count = 0;

	cin >> t;

	while (t--) {
		cin >> n >> m;
		for(int i = 0; i<n; i++){
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> sch_stk[i][j];
			}
			cin >> sch[i];
		}

		for (int i = 1; i <= m; i++) {
			cin >> stk[i];
		}

		for (int i = 0; i < n; i++) {
			bool endflag = 0;
			while (1) {
				for (int j = 0; j < sch_stk[i].size(); j++) {
					int a = sch_stk[i][j];

					if (stk[a] < 1) {
						endflag = 1;
						break;
					}

					stk[a]--;
				}

				if (endflag) {
					break;
				}

				count += sch[n];
			}
		}

		cout << count;
	}
}
