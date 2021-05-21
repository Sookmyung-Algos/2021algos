#include <cstdio>
#include <stdlib.h>
using namespace std;

int main(){
    char s[10]={0, };
    scanf("%s", s);
    for(int i=0;i<10;i++){
        if(s[i]==0) break;
        char temp = s[i];
        int cnt = 0;
        while(temp>0){
            cnt += temp%10;
            temp = temp/10;
        }
        for(int j=0;j<cnt;j++) printf("%c", s[i]);
        printf("\n");
    }
}
