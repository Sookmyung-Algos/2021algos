#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool f(string str1, string str2) {
	int len1 = str1.length(),
		len2 = str2.length();
	
	if (len1 == len2)
		return str1 < str2;
	else return len1 < len2;
}

int main() {
	int n;
	cin >> n;
	string* words = new string[n];
	for (int i = 0; i < n; i++)
		cin >> words[i];
	sort(words, words + n, f);
	cout << words[0] << '\n';
	for (int i = 1; i < n; i++)
		if (words[i].compare(words[i - 1]))
			cout << words[i] << '\n';
	delete[] words;
}
