#include <iostream>
#include <vector>
#define MAX 1000000003
using namespace std;

int N, K;
vector<vector<int>> color;
vector<int> v;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> K;
    v.resize(N);
    for(int i=0;i<N+1;i++)
        color.push_back(v);
    
    for(int i=0;i<=N;i++){
        color[i][0] = 1;
        color[i][1] = i;
    }
    
    // n번색 이전까지는 일렬로 생각, [n][k] 구할 때는 원으로 변형해서 구함
    for(int i=2;i<N;i++){
        for(int j=1;2*j<=i+1;j++){  // 연속되지 않게 선택할 수 있는 j값까지
            color[i][j] = (color[i-2][j-1] + color[i-1][j]) % MAX;
        }
    }
    cout << (color[N-3][K-1] + color[N-1][K])%MAX;
    return 0;
}
