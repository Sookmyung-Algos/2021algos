//baekjoon 2018

#include <iostream>

using namespace std;

int main(void)
{
	int num;
	int count = 0;	//경우의 수 저장할 변수
	cin >> num;

	int sum = 0;
	int start = 1, end = 1;

	while (1) {
		if (sum == num)
			count++;

		if (sum >= num) {	//sum값이 num보다 크거나 같으면 start값 빼고 start 포인터 하나 증가
			sum -= start;
			start++;
		}
		else if (end > num)	//sum이 num보다 작고 end가 num보다 크면 break
			break;
		else {	//sum<num, end <num 이면
			sum += end;
			end++;
		}
	}
	cout << count;
	return 0;
}
