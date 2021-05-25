#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    vector<int> result;
    int T, N, K, target;
    
    cin >> T;
    
    while (T--) {
        cin >> N >> K; // 건물개수 N, 순서개수 K
        
        int connect[1001] = {0, };
        int sum[1001] = {0, };
        vector<vector<int>> loc(1001);
        vector<int> Time(1001);
        queue<int> order;
        
        for (int i = 1; i <= N; i++) { // 건물 시간
            cin >> Time[i];
        }
        
        int x, y;
        
        for (int i = 0; i < K; i++) { // 건물 순서
            cin >> x >> y;
            connect[y]++;
            loc[x].push_back(y);
        }
    
        cin >> target; // 목표건물
        
        for (int i = 1; i <= N; i++) {
            if (connect[i] == 0) {
                order.push(i);
                sum[i] = Time[i];
            }
        }
        
        while (!order.empty()) {
            int q = order.front();
            order.pop();
            for (int j = 0; j < loc[q].size(); j++) { // i 현재 위치
                int next = loc[q][j];
                sum[next] = max(sum[next], sum[q] + Time[next]);
                connect[next]--;
                if(connect[next] == 0){
                    order.push(next);
                }
            }
        }
        result.push_back(sum[target]);
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
}
