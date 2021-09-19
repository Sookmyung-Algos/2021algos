#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int t, n, m;
char c[3001];
bool divconq(int s, int e);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> c;
		if (divconq(0, strlen(c)-1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

bool divconq(int s, int e) {
	if (s == e)
		return true;
	int mid;
	mid = (s + e) / 2;
	for (int i = s; i < mid;i++) {
		if (c[i] == c[e - i])
			return false;
	}
	return divconq(s, mid - 1);
}
