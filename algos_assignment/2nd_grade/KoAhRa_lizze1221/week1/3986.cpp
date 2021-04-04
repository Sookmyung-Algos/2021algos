#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {

		stack <char> stack;

		string word;
		cin >> word;

		for (int i = 0; i < word.length(); i++) {
			if (stack.empty()) { // 만약 stack이 비어있으면
				stack.push(word[i]); // 비교할 값이 없으므로 그냥 push
			}
			else {
				if (stack.top() == word[i]) { // 만약 top이랑 같으면
					stack.pop(); // pop한다.
				}
				else { // 다른 경우에는 그 단어를 push한다.
					stack.push(word[i]);
				}
			}
		}
		if (stack.empty()) { // 마지막에 stack이 비어있다면
			cnt++; // 좋은 단어이므로 개수를 하나 추가해준다.
		}
	}
	cout << cnt;
	
	return 0;
}
