#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	pair<int, int>p[1001][1001];

	for (int i = 0; i <= 1000; i++) {
		p[i][0] = { 0,0 };
		p[0][i] = { 0,0 }; 
	}

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				p[i][j].first = p[i - 1][j - 1].first + 1;
				p[i][j].second = 2;
			}
			else {
				if (p[i - 1][j].first > p[i][j - 1].first) {
					p[i][j].first = p[i - 1][j].first;
					p[i][j].second = 1;
				}
				else {
					p[i][j].first = p[i][j-1].first;
					p[i][j].second = 3;
				}
			}
		}
	}

	string ans;

	if (p[str1.size()][str2.size()].first == 0)
		cout << 0 << '\n';
	else {
		int a = str1.size(), b = str2.size();
		while (p[a][b].first != 0) {
			if (p[a][b].second == 2) {
				ans += str1[a - 1];
				a--; b--;
			}
			else if (p[a][b].second == 3)
				b--;
			else
				a--;
		}
		cout << ans.size() << '\n';
		for (auto i = ans.rbegin(); i != ans.rend(); i++) {
			cout << *i;
		}
	}
	return 0;
}