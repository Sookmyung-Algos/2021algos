#include<bits/stdc++.h>
#define min(a,b) a>b?b:a
using namespace std; 
int main()
{
	int ch[1001]={0, };
	int a[101]={0, }; 
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin >> a[i]; 
        ch[i] = 999999;
    }
    ch[0]=0;
    for (int i=0; i<n; i++) {
        if(a[i]!= 0) {
            for (int j=1; j<=a[i]; j++) {
                if (i+j>=n) ch[i+j]=ch[i]+1;
                else ch[i+j]=min(ch[i+j], ch[i]+1);
            }
        }
    }
    if (ch[n-1]>1001) cout << -1 << "\n";
    else cout<<ch[n-1]<<"\n";
}
