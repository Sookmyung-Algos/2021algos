#include <iostream>
#include <vector>

using namespace std;

int a, b, c;
int x1, x2, y1, y2;

int main()
{
  cin>>a>>b>>c
  cin>>x1>>x2>>y1>>y2;
  
  int c1 = 0, c2 = 0;
  vector<int> v;
  
  v.push_back(x1*a+y1*b+c);
  v.push_back(x2*a+y1*b+c);
  v.push_back(x1*a+y2*b+c);
  v.push_back(x2*a+y2*b+c);
  
  for(auto i : v)
  {
    if(i < 0)
      c1++;
    if(i > 0)
      c2++;
  }
  
  if(c1 && c2)
  {
    cout<<"Poor";
  }
  
  else
  {
    cout<<"Lucky";
  }
}
