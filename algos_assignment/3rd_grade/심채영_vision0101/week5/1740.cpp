#include <iostream>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	long long int N;
	int i;
	long long int sum=0;
	long long int num1=1;
	long long int num2=1;

	cin >> N;
	for(i=0;i<39;i++)
	{
		num1 *= 2;
		num2 *= 3;
	}
	while(1)
	{
		if(N/num1>=1)
			sum+=num2;
		if(num1==1)
			break;

		N = N%num1;
		num1 = num1/2;
		num2 = num2/3;
	}
	cout << sum;

	return 0;
}
