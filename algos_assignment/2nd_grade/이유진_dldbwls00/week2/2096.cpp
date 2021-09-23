#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int arr_max[3] = { 0 }, arr_min[3] = { 0 };
	int temp_max[3] = { 0 }, temp_min[3] = { 0 };
	int n; // 줄 수
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp_max[j]; // 숫자 입력
			temp_min[j] = temp_max[j]; //temp_min에 값 복사
			// 삼항연산자(조건연산자) 사용 "조건 ? a : b"
			// 조건이 참이면 a, 거짓이면 b반환
			temp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]); //temp_max에 알맞는 arr_max를 더함
			temp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]) : arr_min[j]); //temp_min에 알맞는 arr_min을 더함
		}
		// 메모리값 복사 함수 사용 "memcpy(복사받을메모리, 복사할메모리, 복사할데이터의길이)"
		memcpy(arr_max, temp_max, sizeof(int) * 3); //temp_max의 메모리를 arr_max에 복사
		memcpy(arr_min, temp_min, sizeof(int) * 3); //temp_min의 메모리를 arr_min에 복사
	}
	sort(arr_max, arr_max + 3); 
	sort(arr_min, arr_min + 3); 
	cout << arr_max[2] << " " << arr_min[0] << '\n';
	return 0;
}
