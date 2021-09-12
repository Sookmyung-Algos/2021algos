#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int val = 666;
	int cnt = 0;
	while (1){
		for (int i = val; i >= 666; i /= 10){
			if (i % 1000 == 666){
				cnt++;
				break;
			}
		}
		if (N == cnt) break;  //N번째 영화인지 확인
		else val++;
	}
	cout << val;
	return 0;
}
