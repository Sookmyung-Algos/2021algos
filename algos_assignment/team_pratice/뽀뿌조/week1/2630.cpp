#include<iostream>
using namespace std;
int n;
int a[128][128];
int b,w;
void paper(int y,int x, int s){
	int hi=a[y][x];
	for(int i=y;i<y+s;i++){
		for(int j=x;j<x+s;j++){
			if(hi==0 && a[i][j]==1) hi=2;
			else if(hi==1 && a[i][j]==0) hi=2;
			if(hi==2){
				paper(y,x,s/2);
				paper(y,x+s/2,s/2);
				paper(y+s/2,x,s/2);
				paper(y+s/2,x+s/2,s/2);
				return;
			}
		}
	}
	if(hi==0) w++;
	else b++;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	paper(0,0,n);
	cout<<w<<"\n";
	cout<<b<<"\n";
	return 0;
}
