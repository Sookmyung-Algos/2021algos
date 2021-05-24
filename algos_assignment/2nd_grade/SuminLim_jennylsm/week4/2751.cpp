#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++) cin >> p[i]; //정렬할 수 입력받기
	sort(p, p + n);  //정렬하기
	for (int i = 0; i < n; i++) cout << p[i] << "\n";
}
