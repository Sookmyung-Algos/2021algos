#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	string s;
	cin >> s;

	deque<char>dq;

	for (unsigned int i = 0; i < s.length(); i++) {
		while (K && !dq.empty() && dq.back() < s[i]) {  //현재 추가할 숫자가 그 전 숫자보다 작을 때까지 pop_back()해줌
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}

	for (unsigned int i = 0; i < dq.size() - K; i++)  //0번째 index부터 deque size-K인 deque까지 출력
		cout << dq[i];
	cout << '\n';

	return 0;
}
