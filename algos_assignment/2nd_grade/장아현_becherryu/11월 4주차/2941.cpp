#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int num = 0;
	int i = 0; 

	cin >> str;
	
	while (i < str.length()) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=')
				i++;
			else if (str[i + 1] == '-')
				i++;
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == '-')
				i++;
			else if (str[i + 1] == 'z' && str[i + 2] == '=')
				i += 2;
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'j')
				i++;
		}
		else if (str[i] == 'n') {
			if (str[i + 1] == 'j')
				i++;
		}
		else if (str[i] == 's') {
			if (str[i + 1] == '=')
				i++;
		}
		else if (str[i] == 'z') {
			if (str[i + 1] == '=')
				i++;
		}
		num++;
		i++;
	}
	cout << num << endl;
}
