#include <iostream>
#include <queue>

using namespace std;

int main(void)

{
	ios_base::sync_with_stdio(0);   //Fast I/O
	cin.tie(0);
	int n, k, i;
	int count = 0;
	queue<int> q;        
	cin >> n >> k;
	for (i = 1; i <= n; i++)       //받은 숫자만큼 큐에 넣기
		q.push(i);
	cout << "<";
	while(q.size()>1){             //빈 큐가 아니면 반복
		count++;
		if (count%k == 0)          //k번째일 때 출력
			cout << q.front() << ", ";
		else                       //k번째가 아니면 맨 뒤로
			q.push(q.front()); 
		q.pop();                   
	}
	cout << q.front() << ">";        
	return 0;
}
