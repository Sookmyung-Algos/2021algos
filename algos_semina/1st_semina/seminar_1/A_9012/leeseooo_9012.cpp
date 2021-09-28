#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int main() {
	int t, cnt;
	string par;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> par;
		for(int j=0;j<par.length();j++) {
			if (par[j] == '(') {
				cnt++;
			}
			else if (par[j] == ')') {
				cnt--;
			}
			if (cnt < 0) {
				cout << "NO\n";
				break;
			}
		}
		if (cnt > 0)
			cout << "NO\n";
		else if(cnt==0)
			cout << "YES\n";
	}
}
