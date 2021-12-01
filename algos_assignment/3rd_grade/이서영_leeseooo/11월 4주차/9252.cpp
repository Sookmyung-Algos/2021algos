#include <iostream>
#include <algorithm>
#include<string>
#include<stack>
using namespace std;
string a, b;
int lcs[1001][1001];
stack<char>ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				if (lcs[i - 1][j] < lcs[i][j - 1]) {
					lcs[i][j] = lcs[i][j - 1];
				}
				else {
					lcs[i][j] = lcs[i - 1][j];
				}
			}
		}
	}
	int i = a.size(); int j = b.size();
	while (i > 0 && j > 0) {
		//LCS가 바뀌는 경계점에서 문자를 저장, 거꾸로 출력
		if (lcs[i][j] > lcs[i - 1][j] && lcs[i][j] > lcs[i][j - 1] && lcs[i][j] > lcs[i - 1][j - 1]) {
			i--; j--;
			//대각선에 있는 값
			ans.push(a[i]);
		}
		else if (lcs[i][j] == lcs[i][j - 1]) {
			j--;
		}
		else {
			i--;
		}
	}
	cout << lcs[a.size()][b.size()] << '\n';
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}
