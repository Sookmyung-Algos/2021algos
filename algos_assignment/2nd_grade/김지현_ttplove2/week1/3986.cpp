#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;

	while(n--) {
		string word;
		cin >> word;
		stack<char> s;

		for (int i = 0; i != word.length(); i++) {
			if (s.empty()) {
				s.push(word[i]);
			}
			else {
				if (s.top() == word[i]) {
					s.pop();
				}
				else if (s.top() != word[i]) {
					s.push(word[i]);
				}
			}
		}

		if (s.empty()) cnt++;
	}

	cout << cnt << endl;
	return 0;
}
