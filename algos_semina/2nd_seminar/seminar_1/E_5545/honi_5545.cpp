#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,a,b,c,x,y;
    int d[101];
    int sum,mon,result,max=0;
    
    scanf("%d",&n);
    scanf("%d %d",&a,&b);
    scanf("%d",&c);
    for (int i=0;i<n;i++)
        scanf("%d",&d[i]);
    sort(d,d+n);

    for (int i=0;i<=n;i++){
        mon=a+b*i;
        x=i;
        y=n-1;
        sum=0;
        while (x--){
            sum+=d[y];
            y--;
        }
        sum+=c;
        result=sum/mon;
        
        if (result>max)
            max=result;
    }
    printf("%d",max);
}

