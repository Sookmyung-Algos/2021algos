// 17281 야구
#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

int N, maxScore;
int order[10]; // 타순을 저장하는 배열
int result[51][10]; // 각 선수의 이닝 결과를 저장하는 배열
bool isSelected[10]; // dfs 실행 시 이용할 배열. 해당 번호의 선수의 선택 여부를 저장하는 불린 타입 배열

void play()
{
	int score = 0; // 점수 저장 변수
	int start = 1; // 1번 타자부터 시작
	int base[4]; // 베이스의 상태를 저장하는 배열

	for (int i = 1; i <= N; i++) {
		int out = 0; // 아웃한 횟수 카운트
		bool nIning = false; // 새로운 이닝이 시작
		memset(base, 0, sizeof(base)); // base 배열 0으로 초기화

		while (true) {
			for (int j = start; j < 10; j++) {
				int nowP = result[i][order[j]]; // 현재 플레이어의 공격 결과
				if (nowP == 0) out++; // 아웃인 경우
				else if (nowP == 1) { // 안타인 경우
					for (int p = 3; p >= 1; p--) {
						if (p != 3) {
							base[p + 1] = base[p];
							base[p] = 0;
						}
						else {
							if (base[p] == 1) {
								base[p] = 0;
								score++;
							}
						}
					}
					base[1] = 1;
				}
				else if (nowP == 2) { // 2루타인 경우
					for (int p = 3; p >= 1; p--) {
						if (base[p] == 1) {
							if (p == 1) {
								base[p + 2] = 1;
								base[p] = 0;
							}
							else {
								base[p] = 0;
								score++;
							}
						}
					}
					base[2] = 1;
				}
				else if (nowP == 3) { // 3루타인 경우
					for (int p = 3; p >= 1; p--) {
						if (base[p] == 1) {
							base[p] = 0;
							score++;
						}
					}
					base[3] = 1;
				}
				else { // 홈런인 경우
					for (int p = 1; p <= 3; p++) {
						if (base[p] == 1) {
							base[p] = 0;
							score++;
						}
					}
					score++;
				}

				if (out == 3) { // 아웃 횟수가 3번이 되면
					start = j + 1;
					if (start == 10)
						start = 1;
					nIning = true;
					break;
				}
			}
			if (nIning == true) break; // 아웃 횟수가 3번인 경우는 바로 break
			start = 1; // 아니면 이닝이 종료된 것이므로 다시 1번 타자부터 시작한다.
		}
	}
	maxScore = max(maxScore, score);
}

void dfs(int num)
{
	if (num == 10) {
		play();
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (isSelected[i] == true) 
			continue;
		else {
			isSelected[i] = true;
			order[i] = num;
			dfs(num + 1);
			isSelected[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 1; i < N + 1; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> result[i][j];
		}
	}

	isSelected[4] = true; // 4번 타자의 순서는 1번으로 고정
	order[4] = 1;
	dfs(2);

	cout << maxScore << "\n";
	return 0;
}
