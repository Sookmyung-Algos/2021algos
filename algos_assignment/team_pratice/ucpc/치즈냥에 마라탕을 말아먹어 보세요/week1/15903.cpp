#include <iostream>
#include <queue>
#include <vector>
using namespace std;
long long tempNum1, tempNum2;
priority_queue<long long,vector<long long>,greater<long long>>pq;
void sumCards() {
    long long newNum;
    tempNum1 = pq.top();
    pq.pop();
    tempNum2 = pq.top();
    pq.pop();
    newNum = tempNum1 + tempNum2;
    pq.push(newNum);
    pq.push(newNum);
}
int main() {
    int temp, n, m;
    long long sum=0;
    cin >> n >> m;
    while (n--) {
        cin >> temp;
        pq.push(temp);
    }
    while (m--) {
        sumCards();
    }
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}
