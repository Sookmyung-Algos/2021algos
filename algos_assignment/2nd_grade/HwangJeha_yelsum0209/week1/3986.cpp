#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
#define MAX 100

int main() {
	int N, NUM=0;
	char c;

	cin >> N;
	cin.get(c);

	for (int i = 0; i < N; i++) {
		char line[MAX] = {0};
		stack<char> s;

		cin.get(line, MAX);
		for (int j = 0; j < MAX; j++) {
			char ch = line[j];

			if (s.empty()) {
				s.push(ch);
			}
			else if (s.top() == ch)
				s.pop();
			else
				s.push(ch);
		}
		cin.get(c);

		if (s.empty()) {
			NUM++;
		}
	}
	

	cout << NUM << "\n";

	return 0;
}
