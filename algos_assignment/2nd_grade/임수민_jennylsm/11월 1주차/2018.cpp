#include <iostream>
using namespace std;

int main() {
	int N;
	int result = 0;
	int add = 0;
	int start = 1;
	cin >> N;
	
	int i = start;
	while(true){
		if (start == N) {
			result ++;
			break;
		}
		if (add == N) {
			result++;
			start++;
			i = start;
			add = 0;
		}else if (add > N) {
			start++;
			i = start;
			add = 0;
		}
		else if(add < N){
			add += i;
			i++;
		}
	}
	cout << result << endl;

	return 0;
}
