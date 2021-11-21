#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string s;
	bool flag = false;
	int tmp = 0;
	int sum = 0;
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.length()) {
			if (flag == false) {
				sum += tmp;
				tmp = 0;
			}
			else {
				sum -= tmp;
				tmp = 0;
			}
			if (s[i] == '-') flag = true; // - 이후 식은 다 음수로 만들면 풀 수 있다
		}
		else {
			tmp *= 10; //한자리 이상의 수일때
			tmp += s[i] - '0';
		}
	}
	cout << sum;
}
