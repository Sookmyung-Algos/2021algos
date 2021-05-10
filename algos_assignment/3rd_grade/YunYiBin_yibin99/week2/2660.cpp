#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000;
int people[51][51];

int main(){
    int n;
    int a, b;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) people[i][j] = INF;
    while(true){
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        people[a][b] = 1;
        people[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(people[i][k]+people[k][j] < people[i][j])
                    people[i][j] = people[i][k]+people[k][j];
            }
        }
    }
    int min=INF;
    vector<int> cand;
    for(int i=1;i<=n;i++){
        int score = 0;
        for(int j=1;j<=n;j++)
            if(people[i][j]>score) score=people[i][j];
        if(score<min){
            min=score;
            cand = {i};
        }
        else if(score==min) cand.push_back(i);
    }
    cout << min << " " << cand.size() << "\n";
    for(int i:cand) cout << i << " ";
}
