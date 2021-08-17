#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, l;
int hue[201];

bool check(int mid){
    int cnt=0;
    int length=hue[0];
    if(length>mid){
        cnt+=length/mid;
        if(length%mid==0)
            cnt-=1;
    }
    for(int i=0;i<n;i++){
        length=hue[i+1]-hue[i];
        if(length>mid){
            cnt+=length/mid;
            if(length%mid==0)
                cnt-=1;
        }
    }
    if(cnt>m)
        return false;
    else
        return true;
}

int main(){
    scanf("%d %d %d", &n, &m, &l);
    for(int i=0;i<n;i++)
        scanf("%d", &hue[i]);
    hue[n]=l;
    sort(hue, hue+n+1);
    int s=0, e;
    e=hue[0];
    for(int i=0;i<n;i++){
        int tmp=hue[i+1]-hue[i];
        if(tmp>e)
            e=tmp;
    }
    int ans=e;
    while(s<e){
        int mid=(s+e)/2;
        if(check(mid)){
            ans=mid;
            e=mid;
        }
        else{
            s=mid+1;
        }
    }
    printf("%d", ans);
}
