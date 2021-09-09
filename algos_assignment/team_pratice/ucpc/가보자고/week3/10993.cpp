#include <iostream>
#include <cmath>

using namespace std;
int mid;

void draw(int y, int x, int num, int top, int bot) {
   int left = mid - abs(top - y);   // 좌변
   int right = mid + abs(top - y);   // 우변

   if (y == bot && x >= left && x <= right)   // y좌표가 밑변위치와 같고 x좌표가 좌우변 사이에 있다면
      cout << '*';   // 삼각형의 밑변 그리기
   else if (x == left || x == right) {
      if ((top > bot ? top : bot) >= y && (top < bot ? top : bot) <= y)   // x좌표가 좌우변위치와 같고 y좌표가 삼각형 높이 사이(=top과 bot사이)에 있다면
         cout << '*';   // 삼각형의 양변 그리기
      else
         cout << ' ';
   }
   else {
      if (num == 1)
         cout << ' ';   // 공백 채우기
      else
         draw(y, x, num - 1, num % 2 == 0 ? bot + 1 : bot - 1, (top + bot) / 2);
   }

}

int main() {
   int n;
   cin >> n;
   int height = pow(2, n) - 1;
   int width = height*2 - 1;
   mid = width / 2;

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < (n % 2 == 0 ? width - i : width - (mid - i)); j++) {
         if (n % 2 == 0)   // 가장 큰 삼각형이 역삼각형이면
            draw(i, j, n, height - 1, 0);
         else 
            draw(i, j, n, 0, height - 1);
      }
      cout << '\n';
   }
   return 0;
}
