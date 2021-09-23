#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int num[20001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);  //정렬 후 중앙값을 출력
	cout << num[(n - 1) / 2];
}
