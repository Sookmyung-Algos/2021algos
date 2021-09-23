#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	queue<int>q;  //큐 선언
	vector<int>vec(m);  //벡터 선언
	for (int i = 0; i < m; i++)  
		q.push(i + 1);  //큐에 m까지의 값을 순서대로 push 한다.
	int i = 0;
	while (q.size()) {
		for (int k = 0; k < n - 1; k++) { //n번째가 돌아오기 전까지 반복
			q.push((q.front())); //맨 앞에 있는 값을 push하고 그 자리에 있는 값은 pop한다.
			q.pop();
		}
		vec[i] = q.front();  //for문 이후 맨 앞에 있는 값이 n번째 값으로 vec 배열에 저장한다. 
		q.pop();
		i++;
	}
	printf("<%d", vec[0]);
	for (int l = 1; l < m; l++)
		printf(", %d", vec[l]);   //vec 배열의 값을 순서대로 출력한다.
	printf(">\n");
	return 0;
}
