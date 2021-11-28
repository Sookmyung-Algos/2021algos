#include <iostream>
#include <stack>
#include <string>
#define max(a,b)   (((a) > (b)) ? (a) : (b))

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	int dp[1002][1002] = { 0, };
	cin >> a >> b;
	int la = a.length();
	int lb = b.length();
	for (int i = 1;i <= la;i++) {
		for (int j = 1;j <= lb;j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	stack<char> st;
	int id=la, jd=lb;
	while (id >= 1 && jd >= 1) {
		if (dp[id][jd] > dp[id - 1][jd - 1]) {
			if (dp[id][jd] == dp[id - 1][jd])
				id--;
			else if (dp[id][jd] == dp[id][jd - 1])
				jd--;
			else {
				st.push(a[id - 1]);
				id--;jd--;
			}
		}
		else {
			id--;jd--;
		}
	}
	cout << dp[la][lb] << "\n";
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
