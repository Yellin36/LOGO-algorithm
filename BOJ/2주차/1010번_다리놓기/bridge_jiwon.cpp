#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
#include <cstring>

using namespace std;



int main(){
    int T, N, M;
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>N>>M;
        unsigned long long bridge = 1;
        
        //nCm 문제
        if(N > M/2)
            N = M - N;
        for(int j=0;j<N;j++){
            bridge *= M - j;
        }
        for(int j=0;j<N;j++){
            bridge /= j + 1;
        }
        cout<<bridge<<endl;
    }
}
