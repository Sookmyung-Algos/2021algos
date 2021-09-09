#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int N;
   priority_queue<int, vector<int>, greater<int>> Min_heap;

   //입력
   cin >> N;
   //첫 줄만 우선순위 큐에 넣기
   for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;
      Min_heap.push(tmp);
   }
   //두번째 줄부터 우선순위 큐에 하나씩 넣고, 가장 작은 값 빼기
   for (int i = 1; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int tmp;
         cin >> tmp;
         Min_heap.push(tmp);
         Min_heap.pop();
      }
   }
   cout << Min_heap.top() << '\n';
   return 0;
}
