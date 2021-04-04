#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int m, n;
	queue<int> q;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)	//1부터 n까지 들어간 queue 만들기
		q.push(i);
  
	cout << "<" ;
  
	while (q.size() > 1)	//1개가 남기 전까지
	{
		for (int i = 0; i < n-1; i++)		//n-1만큼 실행(그래야 하나가 남게 됨)
		{
			for (int j = 0; j < m - 1; j++)		//1번부터 m-1번까지의 원소를 뒤로 돌리기
			{
				q.push(q.front());	//맨 앞에 있던 원소를 맨 뒤로 넣고
				q.pop();	//맨 앞에 있던 원소는 pop
			}
			cout << q.front() << ", ";	//m번째 원소 출력
			q.pop();	//출력한 원소는 pop
		}
	}
	cout << q.front() << ">";   //front에 있는 원소가 m번째 원소
	return 0;
}
