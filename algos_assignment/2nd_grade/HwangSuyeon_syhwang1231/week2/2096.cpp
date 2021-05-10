//baekjoon 2096 내려가기

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;	//줄의 개수
	cin >> n;
	int maxDP[3] = { 0 };	//각 시작위치(3개)에 따른최댓값과 최솟값을 저장할 배열 
	int minDP[3] = { 0 };
	int input[3] = { 0 };	//사용자가 입력할 숫자 3개
	int temp0, temp1, temp2;

	cin >> maxDP[0] >> maxDP[1] >> maxDP[2];	//첫번째 줄 먼저 입력받기

	for (int i = 0; i < 3; i++)
	{
		minDP[i] = maxDP[i];	//minDP, maxDP 초기값은 처음 입력값으로 
	}
	
	for (int i = 1; i < n; i++)
	{
		//각 행의 숫자들(3개) 입력받기
		cin >> input[0] >> input[1] >> input[2];

		temp0 = maxDP[0];	//값이 바뀌기 때문에 max 비교를 위해 임시변수에 저장
		temp1 = maxDP[1];
		temp2 = maxDP[2];

		//최댓값 구하기(아랫줄에서 윗줄의 수 중 가능한 것을 선택하는 방식으로 생각)
		maxDP[0] = max(temp0, temp1) + input[0];
		maxDP[2] = max(temp1,temp2) + input[2];
		maxDP[1] = max(max(temp0, temp1), temp2) + input[1];

		temp0 = minDP[0];	//값이 바뀌기 때문에 min 비교를 위해 임시변수에 저장
		temp1 = minDP[1];
		temp2 = minDP[2];

		//최솟값 구하기
		minDP[0] = min(temp0, temp1) + input[0];
		minDP[2] = min(temp1, temp2) + input[2];
		minDP[1] = min(min(temp0,temp1), temp2) + input[1];
	}
	cout << max(max(maxDP[0], maxDP[1]), maxDP[2]);		//최댓값들만 모아놓은 배열에서 최댓값 찾아 출력
	cout << " ";
	cout << min(min(minDP[0], minDP[1]), minDP[2]);		//최솟값들만 모아놓은 배열에서 최솟값 찾아 출력
	return 0;
}
