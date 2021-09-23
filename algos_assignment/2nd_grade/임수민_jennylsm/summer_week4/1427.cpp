#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int arr[10] = {
		0, };
	int len = 0;
	while (N > 0){
		arr[len++] = N % 10;
		N /= 10;
	} //각 자리수를 배열에 저장
	sort(arr, arr + len); //정렬
	for (int i = len; i > 0; i--)
		cout << arr[i - 1];
	return 0;
}
