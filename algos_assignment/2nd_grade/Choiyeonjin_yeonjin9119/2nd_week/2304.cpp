#include <iostream>
#include <stack>
 
using namespace std;
 
stack<int> st;
int N;
int arr[1001];
int pos, len;
int first = 1001, last, longest;
int result;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N;
 
    while (N--)
    {
        cin >> pos >> len;
        arr[pos] = len;
        if (last < pos) last = pos;
        if (first > pos) first = pos;
        if (len > arr[longest]) longest = pos;
    }
 
    for (int i=first; i<=longest; i++)
    {
        if (arr[i])
        {
            if (st.empty()) st.push(arr[i]);
            else if(arr[i] > st.top()) st.push(arr[i]);
        }
        result += st.top();
    }
 
    while (!st.empty()) st.pop();
 
    for (int i=last; i>longest; i--)
    {
        if (arr[i])
        {
            if (st.empty()) st.push(arr[i]);
            else if(arr[i] > st.top()) st.push(arr[i]);
        }
        result += st.top();
    }
 
    cout << result;
 
    return 0;
}
