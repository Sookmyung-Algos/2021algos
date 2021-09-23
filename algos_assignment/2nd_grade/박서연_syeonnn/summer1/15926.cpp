#include<iostream>
#include<string>
#include<stack>

using namespace std;

int n;
string br;
stack<int> s;

int main() {
	cin >> n >> br;

	s.push(-1);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (br[i] == '(') s.push(i);
		else {
			s.pop();
			if (!s.empty()) 
				ans = max(ans, i - s.top());	// 현재위치-s.top()과 기존 답을 비교
			else 
				s.push(i);
		}
	}
	cout << ans;
}
