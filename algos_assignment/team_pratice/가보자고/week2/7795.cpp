#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int aElement, vector<int> B, int left, int right) {  //upper_bound 함수 사용가능
   while (left <= right) {
      int mid = (left + right) / 2;
      if (aElement <= B[mid])
         right = mid - 1;
      else
         left = mid + 1;
   }
   return left;
}

int main(void) {
   int t, a, b;

   cin >> t;   //테스트 케이스 개수 입력

   vector<int> A;
   vector<int> B;

   for (int i = 0; i < t; i++) {
      int temp;
      int numOfPair = 0;   //쌍의 개수

      cin >> a >> b;   //A의 수 a, B의 수 b
      for (int i = 0; i < a; i++) {
         cin >> temp;
         A.push_back(temp);
      }
      for (int i = 0; i < b; i++) {
         cin >> temp;
         B.push_back(temp);
      }

      sort(A.begin(), A.end());  // 오름차순 정렬
      sort(B.begin(), B.end());

      for (int i = 0; i < a; i++) {
         int pos = binarySearch(A[i], B, 0, B.size() - 1);
         numOfPair += pos;
      }
      cout << numOfPair << "\n";
      A.clear();
      B.clear();
   }
   return 0;
}
