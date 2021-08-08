#include <cstdio>
using namespace std;

int main(){
    int a, b, c;
    int x1, x2, y1, y2;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
    int tmp1, tmp2;
    if(a*b>=0){
        tmp1=a*x1+b*y1+c;
        tmp2=a*x2+b*y2+c;
        if((tmp1>0&&tmp2<0)||(tmp1<0&&tmp2>0))
            printf("Poor");
        else
            printf("Lucky");
    }
    else{
        tmp1=a*x1+b*y2+c;
        tmp2=a*x2+b*y1+c;
        if((tmp1>0&&tmp2<0)||(tmp1<0&&tmp2>0))
            printf("Poor");
        else
            printf("Lucky");
    }
}
