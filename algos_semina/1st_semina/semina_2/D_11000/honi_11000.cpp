#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct classroom{
    int s;
    int e;
}c[200000];

bool compare(struct classroom a,struct classroom b){
    if (a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    priority_queue<int,vector<int>,greater<int>> q;    //우선순위큐의 오름차순 정렬 선언

    int N;
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>c[i].s>>c[i].e;
    
    sort(c,c+N,compare);        //시작시간 오름차순으로 정렬
    
    q.push(c[0].e);         //맨 처음 시작하는 강의가 끝나는 시간을 큐에 push
    for (int i=1;i<N;i++)
    {
        if (q.top()<=c[i].s)        //큐의 맨 앞의 강의 끝나는 시간(=가장 빨리 끝나는 시간)이 새로운 강의의 시작시간보다 작거나 같은 경우
            q.pop();                //큐 pop(같은 강의실 사용 가능하므로 강의실 하나 감소)
        q.push(c[i].e);             //큐에 새로운 강의의 끝나는 시간을 push(강의실 하나 추가)
    }
    cout<<q.size();             //큐의 크기 = 필요한 강의실 개수
}
