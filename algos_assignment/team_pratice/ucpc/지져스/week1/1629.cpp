#include<iostream> 
using namespace std; 

long long A, B, C; 
long long pow(int A, int B, int C) { 
  if (B == 0) 
   return 1; 
  long long temp = POW(A, B/2, C); 
  temp = temp * temp % C; 
  if (B % 2 == 0) 
   return temp; 
  else 
   return temp * A % C; 
} 
int main(void) { 
  cin >> A >> B >> C; 
  cout << pow(A, B, C); 
  return 0; 
}
