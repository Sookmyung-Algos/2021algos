#include <iostream>
using namespace std;

int main(void) {
    int arr[5]; // 다섯 개의 수를 담을 배열
    
    for (int i = 0; i < 5; i++) 
        cin >> arr[i]; // 배열에 수 입력

    int answer = 1; // 변수 선언 및 초기화
    
    while (1) {
        int cnt = 0;
        // answer가 1일 때부터 반복
        for (int i = 0; i < 5; i++) // answer를 배열에 있는 모든 수로 나누었을 때 나머지가 0이라면
            if (answer >= arr[i] && answer % arr[i] == 0) cnt++; // cnt 증가
      
        if (cnt >= 3) { // 적어도 3개의 수로 나눠진다면
            cout << answer << '\n'; // 그 값 출력하고
            break; // while문 종료
        }
        answer++; // answer값 증가하면서 반복
    }

    return 0;
}
