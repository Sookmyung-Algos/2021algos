//max heap, min heap 사용하여 문제 풀이
//규칙 1. 최대힙 크기 = 최소힙 크기 or 최대힙 크기 = 최소힙 크기+1 을 항상 만족
//규칙 2. 최소힙의 top원소>=최대힙의 top원소(즉, 최소힙의 모든 원소들이 최대힙 원소들보다 커야함)

#include<iostream>
#include<queue>
 
#define endl "\n"
#define MAX 100010

using namespace std;
 
int N;
int Arr[MAX];

//백준이가 외치는 정수 입력받기
void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Arr[i];
}

//동생이 답해야 하는 중간값 계산 
void Solution() {
    priority_queue<int> Max_PQ, Min_PQ;
    for (int i = 0; i < N; i++) {
        if (Max_PQ.size() > Min_PQ.size()) Min_PQ.push(-Arr[i]);
        else Max_PQ.push(Arr[i]);
        
        if (Max_PQ.empty() == false && Min_PQ.empty() == false) {
            if (Max_PQ.top() > -Min_PQ.top()) {
                int Max_Value = Max_PQ.top();
                int Min_Value = -Min_PQ.top();
 
                Max_PQ.pop(); Min_PQ.pop();
                
                Max_PQ.push(Min_Value);
                Min_PQ.push(-Max_Value);
            }
        }
        cout << Max_PQ.top() << endl;
    }
}
 
void Solve() {
    Input();
    Solution();
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
 
    return 0;
}
