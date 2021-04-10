#include <bits/stdc++.h>

using namespace std;

int main()

{

 vector <int> stack;

 int n;

 cin>>n;

 for (int i=0; i<n; i++)

 {

  string str;

  cin>>str;

  if(str=="push")

  {

   int num;

   cin>>num;

   stack.push_back(num);

  }

  else if(str=="pop")

  {

   if(stack.empty()) cout<<"-1"<<endl;

   else

   {

    cout<<stack.back()<<endl;

    stack.pop_back();

   }

  }

  else if (str=="size") cout<<stack.size()<<endl;

  else if (str=="empty")cout<<stack.empty()<<endl;

  else if(str=="top"){

   if (stack.empty()) cout<<"-1"<<endl;

   else cout<<stack.back()<<endl;   

  }

  else cout<<"ERROR"<<endl;

 }

}

