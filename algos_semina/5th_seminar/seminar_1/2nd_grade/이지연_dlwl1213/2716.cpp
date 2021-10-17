#include <cstdio>

using namespace std;
 
int main(){
    int N;
    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        int len = 0;
        char S[151], c;
        while((c=getchar()) != '\n'){
            S[len++] = c;
        }
        int level = 0, maxlevel = 0;
        for(int j=0; j<len; j++){
            if(S[j] == '['){
                level++;
                if(level > maxlevel) maxlevel = level;
            }
            else level--;
        }
        int result = 1;
        for(int j=0; j<maxlevel; j++)
            result *= 2;
        printf("%d\n", result);
      
    return 0;
}
