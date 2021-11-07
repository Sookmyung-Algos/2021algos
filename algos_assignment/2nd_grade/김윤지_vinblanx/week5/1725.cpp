#include<iostream>
#include<stack>
#define max(a,b) a > b ? a : b

using namespace std;

stack<int> s;
int arr[1000002];
int N = 0;
int ans = 0;
 
int main(void) {
    cin >> N;
 
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
 
    s.push(0);
    for (int i = 1; i <= N+1; i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            int height = arr[s.top()];
            s.pop();
            int width = i - s.top()-1;
 
            ans = max(ans, height*width);
        }
        s.push(i);
    }
 
    cout << ans;
 
    return 0;
}
