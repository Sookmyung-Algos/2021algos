#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int n, k;
	string str;
	deque<char> dq;
	
	cin >> n >> k >> str;
	
	for (int i=0; i<str.length(); i++) {
        //현재 추가할 숫자가 그 전 숫자보다 작을 때까지 pop_back
		while (k && !dq.empty() && dq.back() < str[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	
	for (int i=0; i<dq.size()-k; i++)	cout << dq[i]; //결과 출력
	cout << "\n";
	
	return 0;
}
