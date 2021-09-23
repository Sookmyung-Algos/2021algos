#include<iostream>
#include<cmath>
using namespace std;

int main(void){
	long long T, i, j, k, x, y; 
	long long d, ans;
	cin >> T;
	for (i = 0; i < T; i++){
		ans = 0;
		cin >> x >> y;
		d = y - x;
		if (d == 0) ans = 0;
		else if (d == 1) ans = 1;
		else if (d == 2) ans = 2;
		else{
			if (sqrt(d) - (int)sqrt(d) == 0) ans = sqrt(d) + sqrt(d) - 1;
			else {
				long long obj = sqrt(d);
				if (d + obj < (obj + 1) * (obj + 1)) ans = 2 * obj;
				else  ans = 2 * obj + 1;
			}
		}
		cout << ans << "\n";
	}
}
