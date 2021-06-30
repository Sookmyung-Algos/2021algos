#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t,n,m,cnt;
    int a[20000],b[20000];
    scanf("%d",&t);
    while (t--)
    {
        cnt=0;
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<m;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        
        for (int i=n-1;i>=0;i--)
        {
            for (int j=m-1;j>=0;j--)
            {
                if (a[i]>b[j]){
                    cnt+=(j+1);
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
    
}
