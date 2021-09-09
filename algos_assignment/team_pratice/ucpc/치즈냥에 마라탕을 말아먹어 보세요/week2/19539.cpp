#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int i, n;
	cin >> n;
	int tmp;
	int sum=0;
	int div_2 = 0; 
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		div_2 +=tmp / 2;

	}
	if (sum % 3 != 0) cout << "NO"<<"\n";
    else{
		if (div_2 >= sum / 3) cout << "YES"<<"\n";
		else cout << "NO"<<"\n";
	}
    return 0;
}
