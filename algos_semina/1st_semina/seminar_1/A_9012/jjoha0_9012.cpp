#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str)
{    
   stack<char> st;    
   for (int j = 0; j < str.length(); ++j)
	 {
		if (st.empty() || str[j] == '(')
            st.push(str[j]);
		else if (st.top() == '(')
            st.pop();
	  }
	if (st.empty())
        return true;
	else
        return false;
} 
int main()
{
    int N;
    string str;    
    cin >> N;    
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        if (check(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
