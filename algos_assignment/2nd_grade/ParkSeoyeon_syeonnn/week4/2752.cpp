#include <iostream>
#include <algorithm>
using namespace std; 

int main() { 
	int num, arr[3];
	for (int i = 0; i < 3; i++) { 
		cin >> num; 
		arr[i] = num; 
	}	// 숫자 세 개 입력받고 배열에 넣음
	sort(arr, arr + 3);	// 배열 오름차순 정렬
	for (int i = 0; i < 3; i++) 
		cout << arr[i] << ' ';	// 작은 수부터 큰 수로 차례대로 출력
}
