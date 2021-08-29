#include <iostream>
#include <string>
#include <regex>

using namespace std;

void check(string s)
{
	regex pattern("(100+1+|01)+");
	if (regex_match(s, pattern))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		check(s);
	}
}
