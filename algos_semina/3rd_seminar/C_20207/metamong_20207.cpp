#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	int height=0,length=0,answer=0;
	cin>>n;
	int date_check[365]={0,};
	for(int i=0;i<n;i++){
		int s,e;
		cin>>s>>e;
		for(int j=s;j<=e;j++) date_check[j]++;
	}
	for(int i=1;i<=365;i++){
		if(date_check[i]>0){
			length++;
			height=max(height,date_check[i]);
		}
		else{
			answer+=height*length;
			height=0;
			length=0;
		}
	}
	answer+=height*length;
	cout<<answer;
	
}
