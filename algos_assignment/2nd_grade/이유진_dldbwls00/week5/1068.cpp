#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
pair<int, bool> parent[MAX]; //부모노드, (true: leaf가 아니다, false: leaf)
vector<int> ancestor[MAX];
int N, deleted;

int count(void);

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> parent[i].first;
        parent[parent[i].first].second = true;
    }
    
    for (int i = 0; i < N; i++){//모든 조상
        int curParent = parent[i].first;
        while (curParent != -1){
            ancestor[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }
    cin >> deleted;
    parent[deleted].second = true;  //삭제된 노드는 leaf가 아님
    parent[parent[deleted].first].second = false; //삭제된 노드의 부모는 leaf
    cout << count() << endl;
    return 0;
}
int count(void) { 
    for (int i = 0; i < N; i++) {//조상 중에 deleted가 있으면 삭제된 노드 -> 제외
        for (int j = 0; j < ancestor[i].size(); j++) {
            if (ancestor[i][j] == deleted)   parent[i].second = true; //leaf가 아님
        }
    }

    for (int i = 0; i < N; i++) {
        if (i != deleted)    parent[parent[i].first].second = true; //leaf가 아니다
    }

    int cnt = 0; //개수 세기
    for (int i = 0; i < N; i++) {
        if (parent[i].second == false)  cnt++;
    }
    return cnt;
}
