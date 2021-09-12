// 15649: N과M(1) (Silver 3)
#include <iostream>
#define MAX 9
using namespace std;

int n,m;
bool isUsed[MAX];
int arr[MAX];

void sol(int idx){  // idx는 순열 배열에 현재 저장할 인덱스
    if(idx == m){
        for(int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(isUsed[i])
            continue;
        isUsed[i] = true;
        arr[idx] = i;
        sol(idx+1);  // 재귀 호출
        isUsed[i] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n>> m;
    
    sol(0);
    return 0;
}
