#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
string a, b;
int lcs[1001][1001];
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
	cout << lcs[a.size()][b.size()];
}
