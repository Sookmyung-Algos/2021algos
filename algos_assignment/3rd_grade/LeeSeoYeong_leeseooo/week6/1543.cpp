#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
string key;
int main() {
	int cnt = 0;
	getline(cin, str);
	getline(cin, key);
	if (str.length() < key.length()) {//찾는문자가 더 길때
		cout << 0;
		return 0;
	}
	for (int i = 0; i < str.length(); i++) {
		bool flag = true;
		for (int j = 0; j < key.length(); j++) {
			if (str[i + j] != key[j]) {// str 위치 i부터 j를 세어줌
				flag = false; 
				break;
			}
		}
		if (flag) {
			cnt++;
			i += key.length() - 1;//찾는 위치 key 길이만큼 이동
		}
	}
	cout << cnt;
}
