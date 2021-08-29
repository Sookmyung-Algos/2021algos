#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int len;
string str[1000];
string word;
int main() {
	cin >> word;
	len = word.size();
	str[0] = word;
	for (int i = 1; i < len;i++) {
		str[i] = word.substr(len - i);;
	}
	sort(str, str+len);
	for (int i = 0; i < len; ++i) {
		cout << str[i] << "\n";
	}
}
