#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    
    vector<unsigned long long> lan_wire;
    unsigned long long tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        lan_wire.push_back(tmp);
    }
    
    sort(lan_wire.begin(), lan_wire.end());
    
    unsigned long long left = 1, right = lan_wire[N-1];
    unsigned long long len = 0;
    
    while(left<=right){
        unsigned long long mid = (left + right) / 2;
        unsigned long long cnt = 0;
        for(int i=0;i<N;i++){
            cnt += lan_wire[i] / mid;
        }
        
        if(cnt >= K){
            left = mid+1;
            if(mid > len)
                len = mid;
        }
        else
            right = mid-1;
    }
    
    cout<<len<<endl;
    
}

