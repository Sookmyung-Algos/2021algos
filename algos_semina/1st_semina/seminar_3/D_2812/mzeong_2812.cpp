#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	string str;
	cin >> str;

	deque<char> dq;

	for (int i = 0; i < str.length(); i++)
	{
		while (!dq.empty() && dq.back() < str[i] && K)
		{
			dq.pop_back();
			K--;
		}
		dq.push_back(str[i]);
	}
	
	for (int i = 0; i < dq.size() - K; i++)
		cout << dq[i];

	return 0;
}
