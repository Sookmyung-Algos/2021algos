#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	string str;
	cin >> str;
	int arr[100] = { 0, };

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c >= 'a')
			c -= 32;
		arr[c]++;
	}

	int max = 0;
	char res;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (arr[i] == max)
			res = '?';
		else if (arr[i] > max) {
			max = arr[i];
			res = i;
		}
	}
	cout << res;
	return 0;
}
