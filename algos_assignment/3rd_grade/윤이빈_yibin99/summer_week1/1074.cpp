#include <cstdio>
using namespace std;

int n, r, c;
int cnt=0;
int size=1;

void check(int sr, int sc){
    size/=2;
    int nr, nc;
    int diff[4][2]={{sr, sc}, {sr, sc+size}, {sr+size, sc}, {sr+size, sc+size}};
    for(int i=0;i<4;i++){
        nr=diff[i][0];
        nc=diff[i][1];
        if((nr<=r&&r<nr+size)&&(nc<=c&&c<nc+size))
            break;
        cnt+=size*size;
    }
    if(size>1)
        check(nr, nc);
}

int main(){
    scanf("%d %d %d", &n, &r, &c);
    for(int i=1;i<=n;i++)
        size*=2;
    check(0, 0);
    printf("%d", cnt);
}
