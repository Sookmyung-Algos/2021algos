#include <iostream>
#include <algorithm> //sort를 사용하기 위한 헤더 파일 include
#include <vector> //vector를 사용하기 위한 헤더 파일 include

using namespace std;

bool cmp(string a, string b) { //string a와 b 비교
	if (a.size() == b.size()) //만약 단어의 길이가 같다면
		return a < b; //사전 순으로 정렬
	else //단어의 길이가 같지 않다면
		return a.size() < b.size(); //먼저 입력된 단어의 길이가 더 짧을 때 true 리턴
}

int main(int args, const char* argv[]) {
	vector<string> dic; //단어를 입력 받을 string형 vector 선언

	int N; //단어의 총 개수를 입력 받을 변수 선언
	string word; //단어를 입력 받을 변수 선언

	cin >> N; //단어의 개수 입력 받기
	
	for (int i = 0; i < N; i++) { //총 단어의 개수만큼
		cin >> word; //단어 입력 받기
		dic.push_back(word); //벡터의 끝에 입력 받은 단어 삽입
	}

	sort(dic.begin(), dic.end(), cmp); //cmp를 통해 벡터 정렬
	dic.erase(unique(dic.begin(), dic.end()), dic.end()); //unique를 통해 중복된 요소 제거, erase를 통해 중복 요소가 제거된 뒤의 위치부터 원래 벡터의 마지막 위치 사이의 요소 모두 제거

	for (auto it = dic.begin(); it != dic.end(); it++) { //타입 추론을 이용한 반복자를 통한 벡터 순회
		cout << *it << '\n'; //정렬된 벡터 출력
	}
  
	return 0;
}
