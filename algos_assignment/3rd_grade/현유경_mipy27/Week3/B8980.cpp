//  도착지, 출발지 순으로 정렬하기 -> 최대한 많이 배달해야 하므로
//  벡터의 각 공간을 마을이라 보고, 마을을 지나는 택배 상자를 모두 더하면서 풀기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int start;
    int destination;
    int box;
}TOWN;

/* 도착지, 출발지 기준으로 정렬하기 */
bool compare(TOWN a,TOWN b){
    if (a.destination == b.destination) {
        return a.start < b.start;
    } else {
        return a.destination < b.destination;
    }
}

int main() {
    int n,c,m;
    cin >> n >> c;
    cin >> m;
    
    vector <TOWN> v;
    vector <int> truck(n+1);
    
    for (int i=0;i<m;i++){
        int s,d,box;
        cin >> s >> d >> box;
        v.push_back({s,d,box});
    }
    sort(v.begin(),v.end(),compare);
    
    int res=0;
    for (int i=0;i<m;i++){
        int start = v[i].start;
        int end = v[i].destination;
        int box = v[i].box;
        
        for (int j=start;j<end;j++){
            if (c <= truck[j]+box) box = c-truck[j]; //트럭의 용량이 부족하면 트럭의 남은 용량을 박스로 저장
            truck[j] += box; //각 인덱스에 박스 개수 더하기
        }
        res+=box; //가져다놓을 수 있는 박스의 수 res에 더하기
    }
    cout << res << endl;
    return 0;
}
