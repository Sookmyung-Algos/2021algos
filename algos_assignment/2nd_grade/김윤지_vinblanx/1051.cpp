#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

 

const int MAX = 50;

 

int N, M;

int arr[MAX][MAX];

 

int maxSquare(void)

{

        int result = 1;

 

        for (int i = 0; i < N; i++)

        {

                 for (int j = 0; j < M; j++)

                 {

                         for (int k = 1; k < min(N, M); k++)

                         {

                                 //범위 내에 있고 각 꼭지점들이 같은 숫자라면

                                 if (i + k < N && j + k < M && arr[i + k][j] == arr[i][j] && arr[i + k][j + k] == arr[i][j] && arr[i][j + k] == arr[i][j])

                                          result = max(result, k + 1);

                         }

                 }

        }

        return result * result;

}      

 

int main(void)

{

        cin >> N >> M;

 

        for (int i = 0; i < N; i++)

        {

                 string temp;

                 cin >> temp;

 

                 for (int j = 0; j < M; j++)

                         arr[i][j] = temp[j] - '0';

        }

       

        cout << maxSquare() << endl;

        return 0;

}
