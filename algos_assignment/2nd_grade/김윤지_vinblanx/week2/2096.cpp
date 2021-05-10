#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr_max[3] = { 0 }, arr_min[3] = { 0 }, tmp_max[3] = { 0 }, tmp_min[3] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tmp_max[j];
			tmp_min[j] = tmp_max[j]; //tmp_max 배열의 현재 값을 같은 인덱스의 tmp_min에 복사
			tmp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]); //삼항연산자를 이용하여 arr_max의 최댓값을 tmp_max에 더해주기
			tmp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]) : arr_min[j]); //삼항연산자를 이용하여 arr_min의 최솟값을 tmp_min에 더해주기
		}
		memcpy(arr_max, tmp_max, sizeof(int) * 3); //memcpy 함수를 이용하여 tmp_max의 메모리를 arr_max에 복사해주기
		memcpy(arr_min, tmp_min, sizeof(int) * 3); //memcpy 함수를 이용하여 tmp_min의 메모리를 arr_min에 복사해주기
	}
	sort(arr_max, arr_max + 3); //정렬
	sort(arr_min, arr_min + 3); //정렬

	cout << arr_max[2] << " " << arr_min[0] << '\n'; // 최댓값과 최솟값 출력
}
