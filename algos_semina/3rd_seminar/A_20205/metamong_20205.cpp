#include<iostream>
using namespace std;
bool pixel[105][105];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool hi;
			cin>>hi;
			for(int x=i*m;x<i*m+m;x++){
				for(int y=j*m;y<j*m+m;y++){
					pixel[x][y]=hi;
				}
			}
		}
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			cout<<pixel[i][j]<<' ';
		}
		cout<<"\n";
	}

}
