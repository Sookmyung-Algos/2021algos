#include <iostream>
#include <stack>

using namespace std;

int main(void)

{
	ios_base::sync_with_stdio(0);   //Fast I/O
	cin.tie(0);
	int k, total = 0;
	stack<int> s;                      
	cin >> k;                                 
	int result = 0;
	for (int i = 0; i < k; i++)               
	{
		int num;
		cin >> num;
		if(num==0)                //만약 0이 들어오면 가장 최근에 현재 top위치의 값을 pop
			s.pop();
		else                      //아니면 push
			s.push(num);
	}
	while(!s.empty()) {           //스택이 빌 때까지 스택에 있는 값을 모두 더함
		total += s.top();
		s.pop();
	}
	cout << total << "\n";        //더한 값 출력
	return 0;
}
