#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	deque<char>dq;

	for (int i = 0; i < str.length(); i++) {
		while (!dq.empty() && k > 0 && str[i] > dq.back()) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
		
	while (k--)
		dq.pop_back();

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}
