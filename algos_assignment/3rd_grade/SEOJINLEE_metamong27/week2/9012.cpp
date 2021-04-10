#include <bits/stdc++.h>

using namespace std;

int main()

{

 int n;

 cin>>n;

 for (int i=0; i<n; i++)

 {

  stack<char> s;

  string str;

  cin>>str;

  bool ch=true;

  for(int j=0; j<str.length();j++){

   if(str[j]=='(') s.push(str[j]);

   else if(str[j]==')' && !s.empty()) s.pop();

   else ch=false;

  }

  if(s.size()==0 && ch==true) cout<<"YES"<<endl;

  else cout<<"NO"<<endl;

 }

}
