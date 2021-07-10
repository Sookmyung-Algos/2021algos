#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   string word;
   cin >> word;

   vector<string> v;

   for (int i = 0; i < word.length() - 2; i++) {
      for (int j = i+1; j < word.length() - 1; j++) {
         string temp = word;

         //0~i, i+1~j, j+1~end 각각 뒤집기
         reverse(temp.begin(), temp.begin() + i + 1);
         reverse(temp.begin() + i + 1, temp.begin() + j + 1);
         reverse(temp.begin() + j + 1, temp.end());

         //vector에 넣기.
         v.push_back(temp);
      }
   }

   //vector(변환된 문자열들이 들어있는)를 사전순 정렬.
   sort(v.begin(), v.end());
   //정렬된 것 중 가장 앞 단어 출력.
   cout << v.front() << "\n";
}
