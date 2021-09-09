#include<iostream>
#include<cmath>
using namespace std;
void hello(int n){
	if(n==1){
		cout<<"-";
	}
	else{
		hello(n/3);
		for(int i=0;i<n/3;i++){
			cout<<" ";
		}
		hello(n/3);
	}
}
int main(){
	while(1){
		int n;
		cin>>n;
		if(cin.eof()==true) break;
		hello(pow(3,n));
		cout<<"\n";
	}
}
