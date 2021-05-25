#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    int RGB[1000][3];
    RGB[0][0] = 0;RGB[0][1] = 0;RGB[0][2] = 0;
    
    int r, g, b;
    for(int i=1;i<=N;i++){
        cin>>r>>g>>b;
        RGB[i][0] = min(RGB[i-1][1] , RGB[i-1][2]) + r;
        RGB[i][1] = min(RGB[i-1][0], RGB[i-1][2]) + g;
        RGB[i][2] = min(RGB[i-1][0], RGB[i-1][1]) + b;
    }
    
    
    cout<<min(RGB[N][0], min(RGB[N][1], RGB[N][2]))<<"\n";
    
}

