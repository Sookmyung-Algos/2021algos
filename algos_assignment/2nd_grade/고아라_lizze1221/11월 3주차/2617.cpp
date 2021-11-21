#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> heavier[100], lighter[100];
bool hVisited[100], lVisited[100];

int HDFS(int node){
        int result = 1;

        for (int i = 0; i < heavier[node].size(); i++){
                 if (!hVisited[heavier[node][i]]){
                         hVisited[heavier[node][i]] = true;
                         result += HDFS(heavier[node][i]);
                 }
        }
        return result;
}

int LDFS(int node){
        int result = 1;

        for (int i = 0; i < lighter[node].size(); i++){
                 if (!lVisited[lighter[node][i]]){
                     lVisited[lighter[node][i]] = true;
                     result += LDFS(lighter[node][i]);
                 }
        }
        return result;
}

 
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> M;
        for (int i = 0; i < M; i++){
                 int marble1, marble2;
                 cin >> marble1 >> marble2;

                 heavier[marble1].push_back(marble2);
                 lighter[marble2].push_back(marble1);
        }
    
        vector<bool> result(N + 1);

        for (int i = 1; i <= N; i++){
                 memset(hVisited, false, sizeof(hVisited));
                 memset(lVisited, false, sizeof(lVisited));
                 hVisited[i] = true, lVisited[i] = true;

                 if (HDFS(i) > (N + 1) / 2) result[i] = true;
                 if (LDFS(i) > (N + 1) / 2) result[i] = true;
        }

        int cnt = 0;
        for (int i = 0; i < N + 1; i++)
                 if (result[i]) cnt++;

        cout << cnt << "\n";
        return 0;
}
