#include <cstdio>
#include <queue>
#include <iostream>  
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int N;

int main() {
    scanf("%d", &N);
    for (int n_idx = 0; n_idx < N; n_idx++) {
        int _input_int;
        scanf("%d", &_input_int);
        
        switch (_input_int) {
        case 0:
            if (pq.size()){
                printf("%d\n", pq.top());
                pq.pop();
            }
            else {
                printf("%d\n", 0);
            }
            break;
        default:
            pq.push(_input_int);
            break;
        } 
    } 

    return 0;
}
