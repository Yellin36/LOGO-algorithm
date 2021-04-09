#include <iostream>
#include <vector>

#define INF 100000000

using namespace std;

int t;
int N, M, W;

bool bf() {
    int s, e, t;
    vector<pair<pair<int,int>,int>> edges;      
    
    for(int i = 0 ; i < M ; i++) {
        scanf("%d %d %d", &s, &e, &t);
        edges.push_back({{s,e},t});             
        edges.push_back({{e,s},t});
    }
    for(int i = 0 ; i < W ; i++) {
        scanf("%d %d %d", &s, &e, &t);
        edges.push_back({{s,e},-t});
    }
    vector<int> dist(N+1, INF); 
    dist[1] = 0;                                
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < edges.size() ; j++) {
            int start = edges[j].first.first, 
                end = edges[j].first.second;
            if((dist[end] > dist[start] + edges[j].second)) {
                if(i == N-1) return true;
                dist[end] = dist[start] + edges[j].second;
            }
        }
    }
    return false;
}

int main(void)
{
    scanf("%d", &t);
    scanf("%d %d %d", &N, &M, &W);
    for(int i = 0 ; i < t ; i++) 
        cout << (bf() ? "YES" : "NO") << endl; 
}
