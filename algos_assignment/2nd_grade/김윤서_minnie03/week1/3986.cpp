#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, count = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		stack<char> word; //스택 만들기 ex) ABBA

		string sentence;
		cin >> sentence;

		int len = sentence.length(); //sentence 길이

		for (int j = 0; j < len; j++) {
			if (word.empty()) { //word 비어있는지 확인하고 비어있다면 push
				word.push(sentence[j]); 
			}
			else { //비어있지 않을 때
				if (word.top() == sentence[j]) //top과 sentence[j]가 같다면 pop
					word.pop(); 
				else //같지 않다면 push
					word.push(sentence[j]);
			}
		}

		if (word.empty()) //word가 비어있다면 좋은단어이므로 count++
			count++;

	}

	cout << count;
	return 0;
}
