#include<iostream>
using namespace std;

long long t,n,a,r,m=1e9+7;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	for(cin>>t; t--; ){
		cin>>n;
        a=1;
        n-=2;
        r=2;
		while (n>0) {
			if(n&1)
                a=a*r%m;
			r=r*r%m;
            n/=2;
		}
		cout<<a<<'\n';
	}
}
