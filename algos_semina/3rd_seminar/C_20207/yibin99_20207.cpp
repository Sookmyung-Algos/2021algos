#include <cstdio>
using namespace std;

int cal[366];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int s, e;
        scanf("%d %d", &s, &e);
        for(int i=s;i<=e;i++)
            cal[i]++;
    }
    int width=0, height=0;
    int sum=0;
    for(int i=1;i<=365;i++){
        if(cal[i]==0){
            sum+=width*height;
            width=0;
            height=0;
        }
        else{
            width++;
            height=(cal[i]>height)?cal[i]:height;
        }
    }
    sum+=width*height;
    printf("%d", sum);
}
