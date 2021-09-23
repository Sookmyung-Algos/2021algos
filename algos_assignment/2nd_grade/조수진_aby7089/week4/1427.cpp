#include<iostream>
using namespace std;

void BubbleSort(int *(&arr), int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 1; j < len - i; j++) {
			if (arr[j] > arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void Solution(string & str) {
	int len = (int)str.length();
	int * arr = new int[len]; //동적할당			  
	for (int i = 0; i<len; i++) { //문자열의 인자를 배열에 넣기
		arr[i] = str[i] - '0';
	}
	BubbleSort(arr, len);
	for (int i = 0; i<len; i++) {
		cout << arr[i];
	}
	delete[]arr;  //동적할당 해제
}

int main(void) {
	string str;
	cin >> str;
	Solution(str);
	return 0;
}
