#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0, cnt = 1, arr[n];
    
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < costs.size(); i++) {
        if(costs[i][2] == 0 || arr[costs[i][0]] == arr[costs[i][1]]) continue;
        
        int tmp = arr[costs[i][1]];
        for(int j = 0; j < n; j++) {            //같은 루트를 가진 모든 다리의 루트를 변경
            if(arr[j] == tmp)
                arr[j] = arr[costs[i][0]];
        }
        answer += costs[i][2];
        cnt++;

        if(cnt == n) break;
    }
    return answer;
}
