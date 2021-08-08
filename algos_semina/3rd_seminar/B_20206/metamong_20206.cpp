#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long>v(5);
	long long a,b,c;
	long long x1,x2,y1,y2;
	cin>>a>>b>>c;
	cin>>x1>>x2>>y1>>y2;
	v[1]=a*x1+b*y1+c;
	v[2]=a*x2+b*y1+c;
	v[3]=a*x1+b*y2+c;
	v[4]=a*x2+b*y2+c;			
	int ch[2]={0,};
	for (int i=1;i<=4;i++){
		if(v[i]<0) ch[0]++;
		else if(v[i]>0) ch[1]++;
	}
	if(ch[0]>0 && ch[1]>0) cout<<"Poor";
	else cout<<"Lucky";
}
