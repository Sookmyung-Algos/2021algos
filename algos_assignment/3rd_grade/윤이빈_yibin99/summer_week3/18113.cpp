#include <cstdio>
#include <vector>
using namespace std;

int n, k, m;
int maxl;
vector<int> l;

int cnt(int p){
    int res=0;
    for(int length:l){
        res+=length/p;
    }
    return res;
}

int main(){
    scanf("%d %d %d", &n, &k, &m);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp<=k)
            continue;
        else if(tmp<2*k)
            tmp-=k;
        else
            tmp-=2*k;
        l.push_back(tmp);
        if(tmp>maxl) maxl=tmp;
    }
    int left=1, right=maxl;
    int p=-1;
    while(left<=right){
        int mid=(left+right)/2;
        int c=cnt(mid);
        if(c>=m){
            if(p<mid) p=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    printf("%d", p);
}
