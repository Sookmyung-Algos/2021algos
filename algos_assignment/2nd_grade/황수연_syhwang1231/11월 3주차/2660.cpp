// 2660(Gold 5) - 회장 뽑기
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 1e9
using namespace std;

int n;  // n: 회원 수
int a, b;  // a, b는 친구
int relation[MAX][MAX];  // 직접친구와 간접친구 수에 따른 점수
vector<int> nominee;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                relation[i][j] = 0;
            else
                relation[i][j] = INF;
        }
    }
    
    while(true){
        cin >> a >> b;
        if(a == -1)
            break;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
    
    for(int mid=1; mid<=n; mid++){
        for(int from=1; from<=n; from++){
            for(int to=1; to<=n; to++){
                relation[from][to] = min(relation[from][to], relation[from][mid]+relation[mid][to]);
            }
        }
    }
    
    // 최소 점수 구하기
    int minScore = 1000;
    
    for(int i=1;i<=n;i++){
        int tempMax = 0;
        for(int j=1;j<=n;j++){
            tempMax = max(tempMax, relation[i][j]);
        }
        
        if(tempMax<minScore){  // 회원 i의 최대 점수가 minScore보다 작면
            nominee.clear();  // 더이상 minScore가 최소점수가 아님 -> nominee 벡터 초기화
            minScore = tempMax;
            nominee.push_back(i);
        }
        else if(tempMax==minScore)
            nominee.push_back(i);
    }
    sort(nominee.begin(), nominee.end());
    
    cout << minScore << ' ' << nominee.size() << "\n";
    for(int i=0;i<nominee.size();i++)
        cout << nominee[i] << ' ';

    return 0;
}
