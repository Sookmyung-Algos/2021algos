#include <iostream>
#include <queue> //queue 사용.

using namespace std;

int main(int argc, const char* argv[])
{
	int n, k, count = 0;
	cin >> n >> k;

	queue<int> q;
	
	for (int i = 1; i <= n; i++) //큐에 n명 넣기.
		q.push(i);

	cout << "<"; 

	while (q.size() > 1) 
	{
		count++;

		if (count % k == 0) //count의 배수 번째이면, 큐의 front 출력.
			cout << q.front() << ", ";
		else //아니면 front를 가장 뒤로 push
			q.push(q.front());

		q.pop(); // front 출력하든 가장 뒤로 보내든 이제 front가 필요없으므로 pop해주기.
	}

	cout << q.front() << ">";
	return 0; 
}
