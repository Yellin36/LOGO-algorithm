#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, J, H;
    cin>>N>>J>>H;
    
    int answer = 0;
    
    while(J != H){
        J =(J+1)/2;
        H =(H+1)/2;
        answer++;
    }
    cout<<answer<<"\n";

}

