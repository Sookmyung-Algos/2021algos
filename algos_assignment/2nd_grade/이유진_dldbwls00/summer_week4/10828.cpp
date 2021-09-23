#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string temp;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (temp == "pop") {
			if (!st.empty()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else cout << "-1" << "\n";
		}
		else if (temp == "size") {
			cout << st.size() << "\n";
		}
		else if (temp == "empty") {
			if (st.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (temp == "top") {
			if (!st.empty())    cout << st.top() << "\n";
			else cout << "-1" << "\n";
		}
	}
	return 0;
}
