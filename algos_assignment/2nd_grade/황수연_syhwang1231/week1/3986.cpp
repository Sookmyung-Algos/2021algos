#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	int n;
	int count = 0;  //좋은 단어의 개수, 0으로 초기화
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char> stack;
		string word;	//문자열 생성
		cin >> word;	//문자 입력받기

		for (int j = 0; j < word.length(); j++)		//단어의 길이만큼 검사
		{
			if (stack.empty())	//스택이 빈 경우(단어를 처음 검사하는 경우)
			{
				stack.push(word[j]);  //스택에 문자 넣기
			}
			else  //스택에 문자가 존재하는 경우
			{
				if (stack.top() == word[j])   //만약 검사하려는 문자가 top에 있는 문자와 같다면 pop
					stack.pop();
				else  //다르면 push
					stack.push(word[j]);
			}
		}
		if (stack.empty())	//단어 검사 마친 후 스택이 비어있으면 좋은 단어이므로 count 값 증가
			count++;
	}
	printf("%d\n", count);
	return 0;
}
