#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
    int s, e;
};

struct cmp {
    bool operator()(info& a, info& b) {
        if (a.s == b.s) {
            return a.e > b.e;
        }
        return a.s > b.s;
    }
};

info tmp;

int main() {
    priority_queue<info, vector<info>, cmp> pq;        //전체 강의실
    priority_queue<int, vector<int>, greater<int>> pq2;       //현재 강의중인 강의실
    int num, e, s, result = 1;
    cin >> num;  //강의 개수 입력
    for (int i = 0; i < num; i++) {
        cin >> s >> e;
        tmp.s = s;
        tmp.e = e;
        pq.push(tmp);   //강의 시작시간과 끝나는 시간을 입력받기
    }
    while (!pq.empty()) {
        int cs = pq.top().s;
        int ce = pq.top().e;
        pq.pop();
        if (!pq2.empty()) {
            int r = pq2.top();
            if (r <= cs) pq2.pop();
        }
        pq2.push(ce);    //시작시간과 끝나는 시간을 바탕으로 정렬
        int vv = pq2.size();
        result = max(result, vv);
    }
    cout << result;
    return 0;
}
