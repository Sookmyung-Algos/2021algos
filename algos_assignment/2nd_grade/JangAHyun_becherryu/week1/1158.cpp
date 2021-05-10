#include <iostream>
#include <queue> 

using namespace std;

int main(int argc, const char * argv[])
{
    queue<int> q;
    int N, M, count = 0;
    cin >> N >> M; 

    for (int i = 1; i <= N; i++)
        q.push(i); 
    cout << "<";
    while (q.size() > 1) { //큐가 빌 때까지 반복
        count++;
        if (count % M == 0) cout << q.front() << ", "; //count의 배수번째마다 큐의 첫번째 수를 출력 & pop
        else q.push(q.front()); // count의 배수번째가 아니면 첫번째 수를 뒤로 보내고 pop
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}
