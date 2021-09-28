#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//cin으로 N을 받는다.

	deque<int> dq;
	//deque를 하나 만들어준다.

	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	// 1부터 N까지의 숫자를 push_back으로 넣어준다.

	while (dq.size() != 1)
	{
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	//pop_front로 처음 것을 pop해주고, 그것을 다시 뒤로 넣는다.
	//그다음 앞의 것을 없애준다.

	cout << dq.front() << "\n";
	//마지막에 남은 것을 cout으로 프린트해준다.
	return 0;
}
