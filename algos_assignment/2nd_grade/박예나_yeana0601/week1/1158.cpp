#include <iostream>
#include <queue>

using namespace std;

int main(int args, const char* argv[]) {
    int n, k;
    queue<int> q;int cnt = 0;

    scanf_s("%d %d", &n, &k);
    for (int i = 1; i < n + 1; i++) {
        q.push(i);
    }
    printf("<");
    while (q.size()) {
        if(q.size() ==1){
            printf("%d>", q.front());
            q.pop();
            break;
        }
        for (int j = 1; j < k; j++) {
            q.push(q.front());
            q.pop();
        }
        printf("%d, ", q.front());
        q.pop();
    }
    return 0;
}
