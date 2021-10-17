#include <iostream>
#include <string>
#include <cmath> // pow
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; 
	getchar();
	while (t--) {
		string s; 
		getline(cin, s);
		int h = 0, mx = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') h++;
			else h--;
			mx = max(mx, h);
		}
		cout << (int)pow(2, mx) << "\n";
	}
}
