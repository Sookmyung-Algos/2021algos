#include <iostream> //cin, cout
#include <stack> //stack 사용

using namespace std;

int main(int argc, const char* argv[])
{
	int n, count = 0;

	cin >> n; //단어 개수 입력 받기.

	for (int i = 0; i < n; i++)
	{
		stack<char> stack;
		string word;

		cin >> word; //단어 입력 받기.
		int len = word.length(); //단어의 길이

		for (int j = 0; j < len; j++) //단어 하나가 끝날때까지 실행.
		{
			if (stack.size() != 0) //stack이 empty가 아닐때.
			{
				if (stack.top() == word[j]) //stack의 top과 현재 글자 같으면 top을 꺼냄.
					stack.pop();
				else
					stack.push(word[j]); //다르면 현재 글자 stack에 넣기.
			}
			else //stack이 empty -> 현재 글자 stack에 넣기.
				stack.push(word[j]);
		}
		if (stack.size() == 0) //stack이 비어있으면 좋은 단어-> count 1 증가.
			count++;
	}
	cout << count << '\n';
}
