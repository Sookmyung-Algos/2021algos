#include<iostream> //cin, cout 사용
#include<queue> //queue 헤더
using namespace std; //식별자가 고유하도록 보장

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); 
} //입출력 속도 개선

int main(void) {
	int N, K, count; //입력받을 N,K 현재 순서 저장할 count
	count = 0; //0으로 정의
	cin >> N >> K; //입력받기
	queue<int> q; //큐 생성
	for (int i = 1; i <= N; i++) {
		q.push(i); //반복문을 사용해 1부터 N까지 큐에 저장
	}
	cout << "<"; //출력형식
	while (q.size() > 1) { //1개가 되면 무조건 그한개가 제거되므로 2개 이상일때까지
		count++; //현재 순서 업데이트
		if (count%K == 0) { //현재 순서가 제거 차례라면
			cout << q.front() << ", "; //출력해준후
			q.pop(); //제거
		}
		else { //아니라면
			q.push(q.front()); //큐 뒤에 추가한 후
			q.pop(); //맨 앞은 제거
		}
	}
	cout << q.front() << ">"; //마지막 남은 사람 출력하기
	return 0;
}
