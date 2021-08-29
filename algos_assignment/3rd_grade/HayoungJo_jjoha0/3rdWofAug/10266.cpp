#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 360000;
 
int main(){
    vector<bool> clock1(MAX*2, false), clock2(MAX, false);
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        clock1[a] = true;
    }
    copy(clock1.begin(), clock1.begin()+MAX, clock1.begin()+MAX);
    
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        clock2[a] = true;
    }
 
    // kmp >> pi 배열
    int pi[MAX] = {0}, j = 0;
    for(int i=1; i<MAX; i++){
        while(j > 0 && clock2[i] != clock2[j]) j = pi[j-1];
        if(clock2[i] == clock2[j]) pi[i] = ++j;
    }
 
    // 두 번째 시계 패턴이 큰 시계 안에서 등장하면 possible
    bool result = false;
    j = 0;
    for(int i=0; i<MAX*2; i++){
        while(j > 0 && clock1[i] != clock2[j]) j = pi[j-1];
        if(clock1[i] == clock2[j]){
            if(j == MAX-1){
                result = true;
                break;
            }
            else j++;
        }
    }
    puts(result ? "possible" : "impossible");
}
