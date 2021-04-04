#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    int count = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stack<char> stack;
        string tmp;
        cin >> tmp;
        int len = tmp.length();

        for (int m = 0; m < len; m++) {
            if (stack.size() != 0) {
                if (stack.top() == tmp[m]){
                    stack.pop(); //비교 대상이 스택의 top이랑 같으면 pop
                } else { 
                    stack.push(tmp[m]); //비교 대상이 스택의 top과 다르면 push
                }
            } else {
                stack.push(tmp[m]);
            }
        }
        if (stack.size() == 0) {
            count++;  //stack 쌓인게 없고 비면 좋은 단어니까 count++
        }
    }
    printf("%d", count);
}
