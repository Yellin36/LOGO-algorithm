#include <iostream>
using namespace std;

int main(){
    int N, F;
    scanf("%d %d",&N, &F);
    
    N = (N / 100) * 100;
    
    int i;
    for(i=0;i<100;i++){
        if((N+i) % F == 0)
            break;
    }
    
    if(i < 10)
        cout<<"0"<<i;
    else
        cout<<i;
    
}
