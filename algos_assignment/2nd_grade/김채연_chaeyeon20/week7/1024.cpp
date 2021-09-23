#include <iostream>


using namespace std;




int main(){

    long int n;
    int L;
    cin>>n>>L;

    long int s = -1;
    long int e = -1;

    for(long int i = L ; i <= 100 ; i++){
        // i가 홀수일 때
        if(i%2 == 1){
            if(n%i == 0){
                s = n/i - i/2;
                e = n/i + i/2;
                break;
            }
        }

        // i가 짝수일 때
        else{
            if(n%i == i/2){
                s = n/i - i/2 +1;
                e = n/i + i/2;
                break;
            }

        }
    }
    

    if(s < 0){
        cout<<-1<<endl;
    }
    else{
        for(long int i = s ; i<= e; i++){
            cout<< i <<" ";
        } 
        cout<<endl;
    }




    return 0;
}
