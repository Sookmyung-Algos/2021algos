#include<iostream>
using  namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	int cnt=0, sum=0, min=10001;
	if(n==1) n+=1;
	for(int i=n; i<=m; i++){
		bool hi=true;
		for(int j=2; j*j<=i; j++){
			if(i==2) {
				min=2;
				sum=2;
				break;
			}
			else if(i%j==0){
				hi=false;
				break;
			}
		}
		if(hi==true) {
			cout<<i<<"\n";
			if(i<min) min=i;
		}
	}
}
