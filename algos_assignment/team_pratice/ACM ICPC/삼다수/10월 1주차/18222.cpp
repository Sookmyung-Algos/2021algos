//k번째 문자를 구하기 위해선 k 번째가 해당하는 문자열의 길이를 구해야함 -> 2의 거듭제곱으로 구함
//k번째 문자는 그 전 문자열에서 뒤집어서 붙여준 문자열에 해당
#include <bits/stdc++.h>

using namespace std;

using ll = long long; //k (1 ≤ k ≤ 1018) 

ll f(ll x)
{
	if(x==1)return 0;
	ll i;
	for(i=1;i+i<x;i+=i);
	return !f(x-i);
}

int main() {
	ll n;
	cin>>n;
	
	cout<<f(n);
    
	return 0;
}
