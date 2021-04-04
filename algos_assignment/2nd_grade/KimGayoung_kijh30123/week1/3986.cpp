#include<iostream> //cin, cout 사용
#include<string> //string 헤더
#include<stack> //stack 헤더
using namespace std; //식별자가 고유하도록 보장

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); 
} //입출력 속도 개선

int main(void) {
	while (true) {
		int n; //단어 개수 저장
		int cnt = 0; //좋은단어 개수 저장
		cin >> n; //입력받음
		for (int i = 0; i < n; i++) { //개수만큼 입력받음
			stack<char> stack; //char형으로 스택 생성
			string tmp; //단어를 string형으로
			cin >> tmp; //입력받기
			
			int len = tmp.length(); //단어 길이 저장

			for (int j = 0; j < len; j++) { //한단어씩 반복
				if (stack.size() != 0) { //비어있지 않다면
					if (stack.top() == tmp[j]) { //top과 비교 같으면
						stack.pop(); //빼내기
					}
					else {
						stack.push(tmp[j]);  //다르면 추가하기
					}
				}
				else {
					stack.push(tmp[j]); //스택이 비어있으면
				}//처음엔 비어있고 하나씩 입력받고 짝맞추고 없애고 반복 남아있으면 좋은단어x
			}
			if (stack.size() == 0) { //스택 비었는지 확인
				cnt++;
			}
		}
		printf("%d",cnt); //출력
		return 0; //while 사용했으므로 return 해야 끝남
	}
	
}
