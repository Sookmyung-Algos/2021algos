#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, k, cnt = 0;
	stack<int> ans;
	stack<int> out;
	string num;

	cin >> n >> k;
	cin >> num;
	for (int i = 0; i < n; i++) {
	// 스택이 비지 않았을 때 맨 위의 값과 현재의 값을 비교하여 현재의 값이 더 크면 맨 위 원소를 제거한다
		while (!ans.empty() && ans.top() < (num[i] - '0') && cnt < k) { // k번 이하로 제거하기 위해 cnt 변수 사용
			ans.pop();
			cnt++;
		}
		ans.push(num[i] - '0');
	}
	while (cnt < k) { // k번 이하로 제거되었을 때 남은 횟수 마저 채우기
		ans.pop();
		cnt++;
	}
	for (int i = 0; i < n - k; i++) {
		out.push(ans.top()); // 스택을 뒤집어 출력하기 위해
		ans.pop();
	}

	for (int i = 0; i < n - k; i++) {
		cout << out.top();
		out.pop();
	}


}
