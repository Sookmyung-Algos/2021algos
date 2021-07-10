#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];

int main() {
    int N,K;
    cin >> N >> K;
    
    for (int i=2;i<=N;i++){
        arr[i]=i;
    }
    int cnt=0;
    for (int i=2;i<=N;i++){
        for (int j=1;i*j<=N;j++){ //배수 찾는 조건
            int p = i*j;
            if (arr[p]==-1) continue;
            arr[p]=-1;
            cnt++;
            if (cnt==K){
                cout << p;
                break;
            }
        }
    }
    return 0;
}
