/////////////////////////////////////////////
//작성 날짜: 2021.04.07
//문제: 백준 1158)요세푸스
//기타: queue 사용 예제
/////////////////////////////////////////////

#include <queue>
#include <iostream>
using namespace std;

int main() {

	queue<int> q; // queue만들기
	int N, K;
	int count = 0;

	cin >> N >> K; // 빈 칸을 사이에 두고 순서대로 입력

	for (int i = 1; i <= N; i++){ //1~N까지 원 만들기
		q.push(i);
	}

	cout << "<"; 
	while (q.size() > 1) { //q에 2개 남아있을 때까지
		count++;
		if (count % K == 0){ //if) 7,3인경우 3과 6출력
			cout << q.front() << ","; //출력
		}
		else { //if)7,3인 경우 1,2,4,5,7
			q.push(q.front()); //q에 다시 넣어서 6다음에는 1이 다시 나옴
		}
		q.pop(); //검사하고 제거
	}
	cout << q.front() << ">"; //q에 남아있는 마지막 숫자 출력
	return 0;
}
