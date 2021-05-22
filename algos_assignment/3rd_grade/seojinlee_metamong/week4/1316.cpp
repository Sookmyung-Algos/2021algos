#include<bits/stdc++.h>
using namespace std;
bool al[26];
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		memset(al, false, sizeof(al));
		bool hi = 0;
		char a = str[0];
		al[a - 'a'] = 1;
		for (int j = 1; j < str.length(); j++) {
			if (a == str[j]) continue;
			else {
				a = str[j];
				if (al[a - 'a'] == 0) al[a - 'a'] = 1;
				else {
					hi = 1;
					break;
				}
			}
		}
		if (hi == 0) cnt++;
	}
	cout << cnt;
}
