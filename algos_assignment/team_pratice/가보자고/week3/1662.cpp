#include <iostream>
#include <stack>
#include <string>
using namespace std;

int parLocation[50];  // 괄호의 쌍의 위치를 저장, 인덱스:열린 괄호 위치, 원소 값: 닫힌 괄호의 위치
//int result;
string input;

int solution(int start, int end) {  // 매개변수는 문자열 길이 계산할 범위, 반환 값: 계산한 길이
   int result = 0;
   for (int i = start; i < end; i++) {
      if (input[i] == '(') {
         result += (input[i - 1] - '0') * solution(i + 1, parLocation[i]);
         result--;  // 문자열이 반복되는 숫자가 문자열의 숫자로 계산됨
         i = parLocation[i];  // 위에서 solution함수 통해 괄호안 문자열 길이 계산됐으므로 i 값 새로 갱신
      }
      else if (input[i] == ')')
         continue;
      else
         result++;
   }
   return result;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   stack<char> par;

   int length = 0;
   cin >> input;

   for (int i = 0; i < input.length(); i++) {
      if (input[i] == '(')
         par.push(i);
      else if (input[i] == ')') {
         parLocation[par.top()] = i;  //열린 괄호와 닫힌 괄호 쌍의 위치 저장
         par.pop();
      }
   }

   cout << solution(0, input.length());
   return 0;
}
