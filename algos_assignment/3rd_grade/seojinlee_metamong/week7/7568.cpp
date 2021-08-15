#include<iostream>
using namespace std;
int main(){
	int n,hi=1;
	pair<int,int> a[50];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i].first<a[j].first && a[i].second<a[j].second){
				hi++;
			}
			
		}
			cout<<hi<<" ";
		hi=1;
	}

}
