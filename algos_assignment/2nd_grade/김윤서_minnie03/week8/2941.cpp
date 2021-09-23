#include <iostream>
using namespace std;
#include <string>

string cro; //알파벳을 입력받을 문자열
int cnt; //알파벳 개수
int s; //문자열 길이(사이즈)
int i = 0;

void check(int i) { //알파벳 확인 함수
	                //입력받은 문자열 각 인덱스를 크로아티아 알파벳인지 확인
	                //재귀함수 이용함
	if (i >= s) return;
	if (cro[i] == 'c') {
		if (cro[i + 1] == '=') {
			cnt++;
			check(i + 2);
		}
		else if (cro[i + 1] == '-') {
			cnt++;
			check(i + 2);
		}
		else {
			cnt++;
			check(i + 1);
		}
	}
	else if (cro[i] == 'd') {
		if (cro[i + 1] == 'z') {
			if (cro[i + 2] == '=') {
				cnt++;
				check(i + 3);
			}
			else {
				cnt++;
				check(i + 1);
			}
		}
		else if (cro[i + 1] == '-') {
			cnt++;
			check(i + 2);
		}
		else {
			cnt++;
			check(i + 1);
		}
	}
	else if (cro[i] == 'l' && cro[i + 1] == 'j') {
		cnt++;
		check(i + 2);
	}
	else if (cro[i] == 'n' && cro[i + 1] == 'j') {
		cnt++;
		check(i + 2);
	}
	else if (cro[i] == 's' && cro[i + 1] == '=') {
		cnt++;
		check(i + 2);
	}
	else if (cro[i] == 'z' && cro[i + 1] == '=') {
		cnt++;
		check(i + 2);
	}
	else {
		cnt++;
		check(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> cro; //문자열 입력받음
	s=cro.size(); //입력받은 문자열 크기 저장

	check(0); //0 인덱스부터 문자열 확인

	cout << cnt << endl; //최종 크로아티아 알파벳 개수 출력
	return 0;
}
