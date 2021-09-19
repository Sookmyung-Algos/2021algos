#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
   long long n;
   long long dice[6];
   long long arr[3];
   long long sum = 0;

   cin >> n;

   for (int i = 0; i < 6; i++)
   {
      cin >> dice[i];
   }

   if (n == 1) //주사위 1개일 경우
   {
      sort(dice, dice + 6);
      for (int i = 0; i < 5; i++)
         sum += dice[i];
      cout << sum << endl;
   }

   else
   {
      arr[0] = min(dice[0], dice[5]); //마주보는 면끼리 비교해서 최솟값 구하기
      arr[1] = min(dice[1], dice[4]);
      arr[2] = min(dice[2], dice[3]);

      sort(arr, arr + 3);

      int di1 = arr[0];
      int di2 = arr[0] + arr[1];
      int di3 = arr[0] + arr[1] + arr[2];

      //순서대로 면이 1개, 2개, 3개 보이는 경우에 따라 맞는 di_를 곱해서 sum에 넣어줌
      sum += di1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2)); 
      sum += di2 * (4 * (n - 2) + 4 * (n - 1));
      sum += di3 * 4;

      cout << sum << endl;
   }


   return 0;
}
