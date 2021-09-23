#include <iostream>
#include <stack>
using namespace std;

int K; int sum = 0;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x; cin >> x;
		if (x == 0 && !s.empty()) {
			s.pop();
		}
		else s.push(x);
	}
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << "\n";
	return 0;
}
