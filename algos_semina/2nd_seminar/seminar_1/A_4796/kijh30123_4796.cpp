#include <iostream>

using namespace std;

bool flag = true;
int L, P, V, N, ans;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); //입출력속도 개선
	int count = 0;

	while (flag){
		cin >> L >> P >> V;
		if (L * P * V == 0) {
			return 0;
			flag = false;
		}
		N = V % P;
		if (N>=L) { //나머지 일수가 L보다 큰 경우
			ans = L*(V / P) + L;
		}
		else { //그렇지 않은 경우
			ans = L*(V / P) + N;
		}
		count++;
		cout << "Case" << " " << count << ": " << ans << "\n"; //출력
	}
	return 0;
}
