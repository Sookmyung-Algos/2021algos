#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int t, n;
string str[31];
bool robots[11];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> str[i];
			robots[i] = true;
		}
		int len = str[1].length();
		for (int i = 0; i < len; i++) {
			bool rsp[3] = { false, };
			for (int j = 1; j <= n; j++) {
				if (!robots[j])continue;

				switch (str[j][i]) {
				case 'R':rsp[0] = true; break;
				case 'S':rsp[1] = true; break;
				case 'P':rsp[2] = true; break;
				}
			}
			int check = 0;
			for (int j = 0; j < 3; j++) {
				if (rsp[j])check++;
			}

			if (check == 3 || check == 1)continue; //비긴
			else if (check == 2) {//승부가 난
				char c;
				if (rsp[0] == true && rsp[1] == true) c = 'S';
				else if (rsp[1] == true && rsp[2] == true)c = 'P';
				else if (rsp[2] == true && rsp[0] == true)c = 'R';
				for (int k = 1; k <= n; k++) {
					if (str[k][i] == c) {
						robots[k] = false;
					}
				}
			}
		}
		int win = 0; int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (robots[i]) {
				win++; 
				ans = i;
			}
		}
		if (win == 1) {
			cout << ans << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}
