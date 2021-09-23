#include<bits/stdc++.h>
using namespace std;
void recur(long long n){
	if(n==0) return;
	else{
		recur(n/2);
		cout<<n%2;

	}
}
int main(){
	long long n;
	cin>>n;
	recur(n);
	return 0;
}
