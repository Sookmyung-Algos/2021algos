#include <iostream>
using namespace std;

int main(void) {
	int n;
	long long sum=0;
	cin >> n;
	n--;
	for(int i=n+1; i!=0; i= n/((n/i)+1)){
    	sum+= (n/i+1)*(i-(n/((n/i)+1)));
	}
	cout << sum << endl;
	return 0;
}
