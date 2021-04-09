#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<pair<int, int>, int>> v;
int cost[500]={-1,};
int TC, N, M, W;   //테스트케이스, 지점 수, 도로 개수, 웜홀 개수
int S,E,T;  //시작 지점, 도착 지점, 시간


void Bellman_Ford(){
    cost[1] = 0;
    
    //최단 시간
    for (int i = 1; i <= N - 1; i++){
        for (int j = 0; j < (int)v.size(); j++){
            S = v[j].first.first;
            E = v[j].first.second;
            T = v[j].second;
 
            if (cost[S] == 10001){
                continue;
            }
            if (cost[E] > cost[S] + T){
                cost[E] = cost[S] + T;
            }
        }
    }
 
    //사이클 존재 여부
    for (int i = 0; i < (int)v.size(); i++){
        S = v[i].first.first;
        E = v[i].first.second;
        T = v[i].second;
 
        if (cost[S] == 10001){
            continue;
        }
        if (cost[E] > cost[S] + T){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    
    cin>>TC;
    for(int i=0;i<TC;i++){
        //초기화
        v.clear();
        memset(cost, -1, 500);
        
        cin>>N>>M>>W;
        
        //시작지점, 도착지점, 시간
        for(int j = 0;j<M;j++){
            cin>>S>>E>>T;
            v.push_back(make_pair(make_pair(S, E), T));
            v.push_back(make_pair(make_pair(E, S), T));
        }
        
        //웜홀(시간이 거꾸로간다)
        for(int j = 0;j<W;j++){
            cin>>S>>E>>T;
            v.push_back(make_pair(make_pair(S, E), -T));
        }
        
        Bellman_Ford();
    }
    
}

