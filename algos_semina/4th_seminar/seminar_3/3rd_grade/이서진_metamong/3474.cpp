#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		int k;
		cin>>k;
		int cnt=0;
		for(int j=5; j<=k; j*=5) {
			cnt+=k/j;
		}
		cout<<cnt<<"\n";
	}
}
