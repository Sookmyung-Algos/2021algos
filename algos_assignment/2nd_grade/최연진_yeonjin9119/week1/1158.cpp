/*제거된 사람을 기점으로 k번째 다음에 있는 사람을 제거하는 문제.
즉, k로 나눠 떨어지는 인덱스를 갖는 값을 출력하고,
나누어 떨어지지 않는 값을 인덱스로 갖는 것은 다시 저장해 
queue에 남은 수가 없을 때까지 반복 */
#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int n, m, cnt = 0;//m= 제거될 순번, cnt= 제거될 인덱스
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q.push(i);//큐에 값을 순서대로 저장
	}
	cout << "<";
	while (q.size() > 1) {//큐에 값이 남아있을 때만 반복문이 돌아감
		cnt++;
		if (cnt % m == 0) {//제거될 순번의 값이라면 출력
			cout << q.front() << ", ";
		}
		else {
			q.push(q.front());//제거되지 않는다면 가장 뒤에 다시 저장
		}
		q.pop();//순번에 상관없이 모두 pop(제거되지 않을 값은 뒤에 다시 저장해두었기 때문)
	}
	cout << q.front() << ">";
	return 0;
}
