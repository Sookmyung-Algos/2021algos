#include <cstdio>
using namespace std;

int n;
int paper[129][129];
int wcnt, bcnt;

void check(int r, int c, int size){
    int color=paper[r][c];
    for(int i=r;i<r+size;i++){
        for(int j=c;j<c+size;j++){
            if(paper[i][j]!=color)
                color=-1;
        }
    }
    if(color==0)
        wcnt++;
    else if(color==1)
        bcnt++;
    else{
        size/=2;
        check(r, c, size);
        check(r, c+size, size);
        check(r+size, c, size);
        check(r+size, c+size, size);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &paper[i][j]);
        }
    }
    check(0, 0, n);
    printf("%d\n%d", wcnt, bcnt);
}
