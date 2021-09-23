#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int l, c;
char a[16];

void ans(int k, string str, int ja, int mo) {
	if (str.size() == l) {
		if (ja < 2 || mo < 1) 
			return;
		cout << str << "\n";
	}
	for (int i = k; i < c; i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			ans(i + 1, str + a[i], ja, mo+1);
		}
		else {
			ans(i + 1, str + a[i], ja+1, mo);
		}
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a, a + c);
	ans(0, "", 0, 0);
}
