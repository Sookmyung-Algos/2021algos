#include <iostream> 
#include <algorithm>
#include <string>
using namespace std; 

int sugar (int kg, int turn){
    if( kg == 0 ){
        return turn;
    }
    if( kg < 0){
        return -1;
    }
    if(kg % 5 !=0){
        return sugar(kg-3,turn+1);
    }

    else if (kg % 3 !=0){
        return sugar(kg-5,turn+1);
    }

    else if (kg%5==0){
        return sugar(0,turn+kg/5);
    }
        
    else if (kg%3==0){
        return sugar(0,turn+kg/3);
    }
        
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int kg, t;

    cin >> kg;
    t = sugar(kg, 0);
    cout << t;
}
