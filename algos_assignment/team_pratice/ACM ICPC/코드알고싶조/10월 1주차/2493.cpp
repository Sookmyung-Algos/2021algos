#include <iostream>
#include <stack>
using namespace std;
int tower[500010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	stack<pair<int, int>> st;
	int n, in;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		in = 0;
		cin >> tower[i];
		while (!st.empty()) {
			if (st.top().first > tower[i]) {
				cout << st.top().second << " ";
				in = 1; // 찾음
				break;
			}
			else 
				st.pop();			
		}
		st.push({ tower[i],i });
		if (in == 0)  // 못 찾았다면
			cout << "0 ";	
	}
}
