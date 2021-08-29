#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	string s, t;
	int a = 0, b = 0;
	cin >> s;
	for (a = 1; a < 1000; a++) {
		t = to_string(a);
		if (t == s) {  //A==B인 경우
			if (s.size() == 3) {
				if (s[0] != (a / 100 + 1) + '0') //연속되지 않은 A==B
					b = a;
			}
			else if (s.size() == 2) {
				if (s[0] != (a / 10 + 1) + '0')
					b = a;
			}
			else if (s.size() == 1)
				b = a;
			if (a == b)
				break;
		}
		for (b = a+1; b < 1000; b++) {  //A!=B인 경우
			t += to_string(b);
			if (s.size() == t.size())
				break;
		}
		if (s == t)
			break;
	}
	cout << a << " " << b;
}
