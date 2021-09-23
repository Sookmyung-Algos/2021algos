#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	int n, a, b;
	int c;
	cin>>n>>a>>b;
	cin>>c;
	vector<int> v;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	sort(v.rbegin(), v.rend());
	int hi=c;
	double sum=(double)hi/a;	
	for(int i=0; i<n; i++){
		int temp=hi;
		temp+=v[i];
		int p=a+(b*(i+1));
		if(sum<=(double)(temp/p)){
			sum=(double)(temp/p);
			hi=temp;
		}
		else break;
	}
	cout<<sum;
}
