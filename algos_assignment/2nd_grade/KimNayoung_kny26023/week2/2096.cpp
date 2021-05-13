#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int arr_max[3] = { 0 }, arr_min[3] = { 0 };
	int temp_max[3] = { 0 }, temp_min[3] = { 0 };
	//arr와 temp를 초기화해준다.
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int temp1, temp2;
			cin >> temp_max[j];
			temp_min[j] = temp_max[j];
			if (j == 1) {
				temp1= max(arr_max[0], arr_max[2]);
				temp2 = min(arr_min[0], arr_min[2]);
				//j가 1일 때에는 하나의 경우를 더 봐야 하기 때문에 비교를 해준다.
			}
			else {
				temp1 = arr_max[j];
				temp2 = arr_min[j];
				//j가 1이 아닐 경우에는 경우가 2가지이므로 그냥 하나를 넣어준다.
			}
			temp_max[j] += max(arr_max[1], temp1);
			temp_min[j] += min(arr_min[1], temp2);
			//비교를 해준다.
		}
		memcpy(arr_max, temp_max, sizeof(int) * 3);
		memcpy(arr_min, temp_min, sizeof(int) * 3);
		//비교된 것을 arr_max와 arr_min에 각각 넣어준다.
	}
	sort(arr_max, arr_max + 3);
	sort(arr_min, arr_min + 3);
	//가장 큰 값과 가장 작은 값을 print해준다.
	cout << arr_max[2] << " " << arr_min[0];
}
