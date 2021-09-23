#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int arr_max[3] = { 0 }, arr_min[3] = { 0 };
	int temp_max[3] = { 0 }, temp_min[3] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp_max[j];
			temp_min[j] = temp_max[j];
			temp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]);
			/*max(arr_max[1],( (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]))이라고 생각해야함. 왜냐면 j=1일 경우 0,1,2 번째 모두 갈 수 있기 때문임
			만약 j!=1 이라면 j번째 수와 1번 수를 max함수를 이용해 최종적으로 비교하면 됨.(왜인지는 ppt 50p 참고)*/
			temp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]) : arr_min[j]);
			/*위와 같은 이유*/
		}
		memcpy(arr_max, temp_max, sizeof(int) * 3);
		memcpy(arr_min, temp_min, sizeof(int) * 3);
	}
	sort(arr_max, arr_max + 3);
	sort(arr_min, arr_min + 3);
	cout << arr_max[2] << " " << arr_min[0] << '\n';
	return 0;
}
