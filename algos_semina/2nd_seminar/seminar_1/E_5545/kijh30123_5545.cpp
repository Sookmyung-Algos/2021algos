#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int N, A, B, C, d, ans;

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); //입출력속도 개선
	
	cin >> N;
	cin >> A >> B;
	cin >> C;
	ans = C / A;
	vector<int> arrA;
	for (int i = 0; i < N; i++) {
		cin >> d;
		arrA.push_back(d);
	}
	sort(arrA.begin(), arrA.end(), greater<>());
	
	for (int j = 0; j < N; j++) {
		C = C + arrA[j];
		A = A + B;
		if (ans>C/A) {
			break;
		}
		ans = C / A;
	}
	cout << ans;
	return 0;
}
