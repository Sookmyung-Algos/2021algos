#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#define endl '\n'
using namespace std;
int main() {
	int oddCnt = 0,idx=-1,i;
	int alpha[26] = { 0, };
	string str, ans="", ansReverse;
	cin >> str;
	for (i = 0; i < str.length(); i++)
		alpha[str[i]-'A']++;
	for (i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			oddCnt++;
            alpha[i]--;
			if (oddCnt != 1) {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			else idx = i;
		}
	}
    for (i = 0; i < 26; i++) {
		if (alpha[i] == str.length()) {
			cout << str << endl;
			return 0;
		}
	}
	for (i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 0 && alpha != 0) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans.push_back('A' + i);
			}
		}
	}
	ansReverse = ans;
	reverse(ansReverse.begin(), ansReverse.end());
	if (idx != -1) ans.push_back('A' + idx);
	ans += ansReverse;
	cout << ans << endl;
	return 0;
}
