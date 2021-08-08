#include <iostream>
using namespace std;

int N;
int arr[366];

int solve()
{
	int col = 0, row = 0;
	int sum = 0;

	for (int i = 1; i < 366; i++) {
		arr[i] += arr[i - 1];
		// 각각의 배열에 저장된 값에 이전 인덱스의 값을 더해줌
		// 행과 열의 최댓값 구하기 위함
		if (arr[i] == 0) { 
			//0인 경우는 일정이 없는, 즉 현재 row와 col값이 직사각형의 길이이므로 
			// 넓이를 계산하여 합해주고
			sum += row * col;
			row = 0, col = 0; // 둘은 다시 0으로 지정한다.
		}
		else {// 일정이 있는 경우
			col = max(col, arr[i]);
			row++;
		}
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;// 각 시작과 종료 날짜를 입력받고,
		arr[s] += 1;// 시작 날의 인덱스에는 1을 더하고
		arr[e + 1] -= 1;// 종료 다음 날짜에는 1을 뺌.
		/* 종료 날짜가 아니라 그 다음 날짜에 1을 빼는 이유는 
		* 종료 날짜 인덱스까지 길이에 포함되어야 하기 떄문이다.
		*/
	}
	cout << solve() << "\n";
	return 0;
}
