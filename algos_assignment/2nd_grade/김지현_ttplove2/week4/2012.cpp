#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int main(void)
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int n, x;
	long long sum = 0;  //수의 범위 때문에 int가 아니라 long long형으로 선언한다.
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		sum += abs(i - v[i - 1]); //현재의 등수와 예상 등수의 차의 절댓값을 더함 
	}

	cout << sum;
	return 0;
}
