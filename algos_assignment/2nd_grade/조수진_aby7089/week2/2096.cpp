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
			temp_min[j] = temp_max[j];  //temp_max에서 받은 값을 temp_min에도 똑같이 넣어주기
			temp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]); //그 줄에서 최댓값을 구해 더해주기
			temp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]) : arr_min[j]); //그 줄에서 최솟값을 구해 더해주기
		}
		memcpy(arr_max, temp_max, sizeof(int) * 3); 
		memcpy(arr_min, temp_min, sizeof(int) * 3);
	}
	sort(arr_max, arr_max + 3);  //오름차순 정렬
	sort(arr_min, arr_min + 3);  
	cout << arr_max[2] << " " << arr_min[0] << '\n';  //오름차순 정렬이므로 max값은 맨 뒤에, min값은 맨 앞에 있음
}
