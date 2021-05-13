#include <iostream>

using namespace std;

int main(void) {
	int digits, digitToDelete;
	cin >> digits >> digitToDelete;		//자릿수, 지울 숫자 개수 입력

	string number;	//digit자리의 수 입력(string)
	string result;	//결과 저장할 string
	cin >> number;

	result.push_back(number[0]);
	
	for (int i = 1; i < number.size(); i++) {	//원래 숫자의 자릿수만큼 반복
		while(!result.empty() && digitToDelete > 0 && result.back() < number[i]) {		//result값이 empty가 아니고,가능한 자릿수>0이고,넣으려는 수가 결과값의 제일 뒤보다 클동안
			digitToDelete--;	//삭제할 개수 하나 감소,
			result.pop_back();	//결과에서 숫자 하나 삭제
		}
		result.push_back(number[i]);
	}

	if (digitToDelete > 0) {	//지워야 할 숫자의 개수가 남았다면
		while (digitToDelete--)
			result.pop_back();	//result의 맨 뒤에서부터 하나씩 지우기
	}

	cout << result;
	return 0;
}
