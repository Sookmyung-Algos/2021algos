#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n, m;
map<int, string>mnum;
map<string, int>mstr;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mstr.insert({ s,i });
		mnum.insert({ i,s });
	}
	for (int i = 0; i < m; i++) {
		string op;
		cin >> op;
		if (op[0] >= 'A' && op[0] <= 'Z') {
			cout << mstr[op] << '\n';
		}
		else {
			int intop = stoi(op);
			cout << mnum[intop] << '\n';
		}
	}
}
