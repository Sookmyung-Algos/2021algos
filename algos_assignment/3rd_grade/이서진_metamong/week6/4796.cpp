#include <iostream>
using namespace std;
int main()
{
	int L, P, V, sum, cnt=1;
	while(1){
		cin>>L>>P>>V;
		if (L==0 && P==0 && V==0) break;
		sum=L;
		sum*=V/P;
		sum+=V%P>L?L:V%P;
		cout<<"Case "<<cnt<<": "<<sum<<"\n";
		cnt++;
	}

}
