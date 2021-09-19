#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
string a, b;
int dp[1001][1001];
int main() {
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {//비교하고 있는 문자가 같다면
				dp[i][j] = dp[i - 1][j - 1] + 1;//현재 문자빼고 이전 문자열 비교한 값 + 1
			}
			else {//비교하고 있는 문자가 다르다면
				//a,b 각각의 문자를 넣었을때 더 큰 값으로 갱신
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.length()][b.length()];
}
