#include <bits/stdc++.h>

using namespace std;

int main()

{

 stack<int> s;

 int n;

 long long sum=0;

 cin>>n;

 for (int i=0; i<n; i++)

 {

  int score;

  cin>>score;

  if(score!=0) s.push(score);

  else if(score==0)

  {

   if(s.empty()) cout<<"-1"<<endl;

   else s.pop();

  }

 }

 while(!s.empty()){

  sum+=s.top();

  s.pop();

 }

 cout<<sum<<endl;

}
