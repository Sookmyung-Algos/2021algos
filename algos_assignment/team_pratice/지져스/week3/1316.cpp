// 1316
// 알파벳을 순자로 치환
// 점점 커지는 순이 아니라면 체커에 포함 안됨

// 알파벳 배열 만들기
// 들어온 문자 있으면 0->1로 치환

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	int N, cnt;
	cin >> N; 
	cnt = N;

	for (int i = 0; i < N; i++) {
		char string[100];
		cin >> string; // 문자열 입력

		int alphabet[26] = { 0, }; // 알파벳 배열 초기화
		int num[100];

		for (int i = 0; i < strlen(string); i++) {
			num[i] = string[i] - 'a'; // 숫자로 변환
			
			int check_num;
			check_num = num[i];

			if (i > 0) {
				if (check_num == num[i - 1]) {
					continue;
				}
				else {
					if (alphabet[check_num] == 0)
						alphabet[check_num] = 1;
					else if (alphabet[check_num] == 1) {
						cnt = cnt - 1;
						break;
					}
				}
			}
			else if (i == 0) {
				if (alphabet[check_num] == 0)
					alphabet[check_num] = 1;
				else if (alphabet[check_num] == 1) {
					cnt = cnt - 1;
					break;
				}
			}
			
		}
	}
	cout << cnt << "\n";
	return 0;
}
