#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        //input
        int N, K, W;
        cin>>N>>K;
        
        vector<vector<int>> Line(N+1);
        vector<int> Time;
        vector<int> Result(N+1,0);
        vector<int> connect(N+1,0);
        int a, b;
        Time.push_back(0);
        for(int j=0;j<N;j++){
            cin>>a;
            Time.push_back(a);
        }
        
        for(int j=0;j<K;j++){
            cin>>a>>b;
            Line[a].push_back(b);
            connect[b]++;
        }
        
        cin>>W;
        // input-end
        
        
        //end-node
        queue<int> que;
        for(int j=1;j<=N;j++){
            if(connect[j] == 0){
                que.push(j);
                Result[j] = Time[j];
            }
        }
        
        while(!que.empty()){
            /*for(int i=1;i<=N;i++){
                cout<<Result[i]<<" ";
            }
            cout<<endl;*/
            
            int now = que.front();
            que.pop();
            
            for(int j=0;j<Line[now].size();j++){
                int next = Line[now][j];
                Result[next] = max(Result[next], Result[now] + Time[next]);
                connect[next]--;
                
                if(connect[next] == 0)
                    que.push(next);
            }
        }
        
        
        
        cout<<Result[W]<<endl;
    }
    
    
}

