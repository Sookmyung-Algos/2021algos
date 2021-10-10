#include <iostream>
#include <string.h>
using namespace std;

int dp[301][3];
int score[301], n;
int sol(int x, int cnt){ //현재 연속으로 밟은 계단의 개수
    if (x == n) return 0;
    int& ret = dp[x][cnt];
    if (ret != -1)    return ret;
    ret = -100000000;
    if (cnt < 2)  ret = max(ret, sol(x+1, cnt+1) + score[x+1]);
    if (x < n-1)  ret = max(ret, sol(x+2, 1) + score[x+2]); //한 칸 더 건너뛰는 경우
    return ret;
}
int main(){
    cin >> n;
    for (int i=1; i<=n; i++)    cin >> score[i];
    memset(dp, -1, sizeof(dp));
    cout << sol(0,0);
}​
