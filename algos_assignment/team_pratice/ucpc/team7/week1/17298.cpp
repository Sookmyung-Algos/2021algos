#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
   int n;

   cin >> n;
   vector <int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];

   stack<int> s;
   vector<int> nge(n);
   for (int i = 0; i < n; i++) // 오큰수 찾기
   {
      while (!s.empty() && v[s.top()] < v[i]) //v[i]가 오큰수일 때
      {
         nge[s.top()] = v[i];
         s.pop();
      }
      s.push(i);
   }

   while (!s.empty()) //오큰수를 못 찾았을 때
   {
      nge[s.top()] = -1;
      s.pop();
   }

   for (int i = 0; i < n; i++)
      cout << nge[i] << " ";

   return 0;
}
