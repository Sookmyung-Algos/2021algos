#include <iostream>

#include <vector>

#include <queue>

#include <functional>

#include <algorithm>

using namespace std;

 

int N;

priority_queue<int, vector<int>, greater<int>> positive;

priority_queue<int> negative;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0); //cin 속도 향상

        cin >> N;

 

        int one = 0, zero = 0;

        for (int i = 0; i < N; i++)

        {

                 int num;

                 cin >> num;

 

                 if (num == 1)

                         one++;

                 else if (num > 0)

                         positive.push(num);

                 else if (num == 0)

                         zero++;

                 else

                         negative.push(num);

        }

 

        //짝이 없는 양수를 위해 1을 곱해준다

        if (positive.size() % 2)

                 positive.push(1);

        //0이 존재한다면 짝이 없는 음수에 0을 곱해준다

        //0이 존재하지 않는다면 짝이 없는 음수에 1을 곱해준다

        if (negative.size() % 2)

                 zero == 0 ? negative.push(1) : negative.push(0);

        int sum = 0;

        //양수들을 합해주고

        while(!positive.empty())

        {

                 int num1 = positive.top();

                 positive.pop();

                 int num2 = positive.top();

                 positive.pop();

 

                 sum += (num1*num2);

        }

        //음수들을 합해준다

        while(!negative.empty())

        {

                 int num1 = negative.top();

                 negative.pop();

                 int num2 = negative.top();

                 negative.pop();

                

                 sum += (num1*num2);

        }

        //1들은 그냥 더해준다

        cout << sum + one << "\n";

        return 0;

}      
