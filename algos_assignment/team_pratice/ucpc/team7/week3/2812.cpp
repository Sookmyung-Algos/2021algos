#include <string>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	deque<char> dq;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++) // 스택 내의 숫자를 비교해 제거/유지
	{
		while (!dq.empty() && dq.back() < str[i] && k > 0)
		{
			dq.pop_back();
			k--;
			
		}
		dq.push_back(str[i]);
	}
	
	for (int i = 0; i < dq.size() - k; i++) //결과 값 출력
		cout << dq[i];
	
	cout << endl;

	return 0;
}
