#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int N;
   vector<int> num;

   //입력받기
   cin >> N;
   for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;
      num.push_back(tmp);
   }

   priority_queue<int> Max_heap; //큰 값이 우선
   priority_queue<int, vector<int>, greater<int>> Min_heap; //작은 값이 우선

   for (int i = 0; i < N; i++) {
      if (Max_heap.size() > Min_heap.size())
         Min_heap.push(num[i]);
      else 
         Max_heap.push(num[i]);

      if (!Max_heap.empty() && !Min_heap.empty() ) {
         if (Max_heap.top() > Min_heap.top()) {
            int Max_value = Max_heap.top();
            int Min_value = Min_heap.top();
            Max_heap.pop();
            Min_heap.pop();

            Max_heap.push(Min_value);
            Min_heap.push(Max_value);
         }
      }

      cout << Max_heap.top() << '\n';
   }
   return 0;
}
