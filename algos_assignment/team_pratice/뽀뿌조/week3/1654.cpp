#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void)
{
	long long k,n,hi=0,ans;
	long long now=0,left,right,mid,index=0;
	left=1;
	right=pow(2,31)-1;
	vector<long long>v;
	cin>>k>>n; 
	for(int i=0;i<k;i++){
		cin>>hi;
		v.push_back(hi); 
	}
	while(left<= right){
		mid=(left+right)/2;
		for(index=0; index<v.size();index++){
			now+=v[index]/mid;
		}
		if(now>=n) {
			left=mid+1; 
			now=0;
		}
		else if(now<n){
			right=mid-1;
			now=0;		
		}
	}	
	ans=right;
	cout<<ans;
}
