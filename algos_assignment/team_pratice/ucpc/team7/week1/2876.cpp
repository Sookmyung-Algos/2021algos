#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int n, a, b; 
   cin >> n;
   vector<int> A;
   vector<int> B;

   for (int i = 0; i < n; i++)
   {
      cin >> a >> b;
      A.push_back(a);
      B.push_back(b);
   }

   int min_grade = 0;
   int max_students = 0;
   for (int g = 1; g <= 5; g++) //같은 grade가 연속으로 있는 학생의 최대 수 구하기
   {
      int students = 0;
      for (int i = 0; i < n; i++)
      {
         if (g == A[i] || g == B[i])
            students++;
         else //초기화 시켜서 연속된 grade만 색칠할 수 있게 함
            students = 0;

         if (students > max_students)
         {
            max_students = students;
            min_grade = g;
         }
      }
   }

   cout << max_students << " " << min_grade << endl;

   return 0;
}
