#include <iostream>
using namespace std;

int main()
{
  int units, tens, eachsum = 0;
	int count = 0;
	int n, newnum;
	cin >> n;
  newnum = n;
	while (1)
	{
        tens = newnum / 10;
        units = newnum % 10;		
        eachsum = (tens + units);   
		    newnum = eachsum % 10 + (newnum % 10 * 10);
        count++;
        if (newnum == n)
           break;
	}
	cout << count;
}
