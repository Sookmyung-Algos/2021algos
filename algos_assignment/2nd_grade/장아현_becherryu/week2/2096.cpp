//슬라이딩 윈도우 (n개 원소 배열, w넓이 창문, 두 포인터의 간격 w일정)
//이전의 정보를 활용해 메모리 사용 줄이기
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() { //n행 3열
    int arr_max[3] = {0}, arr_min[3] = {0}; 
    int temp_max[3] = {0}, temp_min[3] = {0};
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) { //행
        for (int j = 0; j < 3; j++) { //열
            cin >> temp_max[j];
            temp_min[j] = temp_max[j];
            temp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]):arr_max[j]);
            temp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]):arr_min[j]);
        }
        memcpy(arr_max, temp_max, sizeof(int) * 3); //메모리카피 => arr_max에 temp_max를 복사 => 이후 활용
        memcpy(arr_min, temp_min, sizeof(int) * 3);
    }
    sort(arr_max, arr_max + 3); //3개의 값 정렬
    sort(arr_min, arr_min + 3);
    cout << arr_max[2] << " " << arr_min[0] << '\n'; //max의 최대값을 선택, min의 최소값을 선택
    return 0;
}
