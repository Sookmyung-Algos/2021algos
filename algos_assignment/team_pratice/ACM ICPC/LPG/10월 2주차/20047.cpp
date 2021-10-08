#include <cstdio>
int n, x, y;
char S[10001], T[10001], fingers[2];

int findAnswer(int index, int fingerCnt){
    if(index + fingerCnt == n) return 1;

    if(S[index] == T[index + fingerCnt]){
        if(findAnswer(index + 1, fingerCnt)) return 1;
    }
    
    if(fingerCnt == 2)return 0;

    if(fingers[fingerCnt] == T[index + fingerCnt]){
        if(findAnswer(index, fingerCnt + 1)) return 1;
    }

    return 0;
}


int main(){
    scanf("%d\n%s\n%s\n%d %d", &n, S, T, &x, &y);
    fingers[0] = S[x], fingers[1] = S[y];

    int t = 0;
    for(int i = 0; i < n; i++){
        if(i == x || i == y)continue;
        S[t] = S[i];
        t++;
    }

    printf("%s\n", findAnswer(0, 0) ? "YES" : "NO");
}
