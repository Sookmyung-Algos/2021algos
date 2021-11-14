#include <iostream>
#include <string>
using namespace std;
 
int num = 0;
int m = 0;
string tmp = "";
string s;
 
int main(void) {
	cin >> s;
 
	for (int i = 0; i <= s.size(); ++i){
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (m) {
				num -= stoi(tmp);
			}
			else {
				num += stoi(tmp);
			}
 
			if (s[i] == '-') {
				m = 1;
			}
 
			tmp = "";
			continue;
		}
 
		tmp += s[i];
	}
 
	cout << num;
	
	return 0;
}
