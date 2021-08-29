#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int N, K; // 숫자의 자릿수 N. 지울 숫자의 갯수 K
	cin >> N >> K;
	string number; // 입력되는 숫자 number
	cin >> number;
	deque<char> dq;
	for (int i = 0; i < number.size(); i++) {
		while (K != 0 && !dq.empty() && dq.back() < number[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(number[i]);
	}
	for (int i = 0; i < dq.size() - K; i++) {
		cout << dq[i];
	}
	cout << "\n";
}
