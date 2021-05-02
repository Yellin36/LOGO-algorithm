#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, L;
    cin>>N>>L;
    
    vector<pair<int, int>> pool;
    int start, end;
    for(int i=0;i<N;i++){
        cin>>start>>end;
        pool.push_back(make_pair(start, end));
    }
    
    sort(pool.begin(), pool.end());
    
    int answer = 0, now =0;
    for(int i=0;i<N;i++){
        if(now >= pool[i].second)
            continue;
        now = max(now,pool[i].first);
        
        int tmp = (pool[i].second - now -1) / L + 1;
        answer += tmp;
        now += L * tmp;
    }
    
    cout<<answer<<endl;
    
    
}

