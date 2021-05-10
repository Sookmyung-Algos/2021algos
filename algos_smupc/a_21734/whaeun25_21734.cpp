#include<iostream>
#include<string>

using namespace std;

int calculate(char c) {
	int a = (int)c;
	a = a / 100 + a / 10 - a / 100  * 10 + a % 10;
	return a;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	
    string s;
	cin >> s;
	
    for (int i = 0; i < s.length(); i++) {
		int num = calculate(s[i]);
		for (int j = 0; j < num; j++) {
			cout << s[i];
		}
		cout << "\n";
	}
}
