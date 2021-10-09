#include <iostream>
#include <stack>
using namespace std;
int NGE[1000002];
int A[1000002];
int main() {

	int n, a, max = 0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty()) {
			if (A[i] < s.top()) {
				NGE[i] = s.top();
				s.push(A[i]);
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			NGE[i] = -1;
			s.push(A[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << NGE[i] << " ";
	}
	cout << "\n";
}
