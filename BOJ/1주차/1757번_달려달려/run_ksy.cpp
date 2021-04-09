#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N, M;
int dp[10001][501];
vector<int> d;
 
int knapsack(int pos, int m) {
   
    if (pos == N - m) return 0;
    if (pos > N - m) return -99999999;
    if (dp[pos][m] >= 0) return dp[pos][m];
    int ret = 0;
    if (m < M) {
        if (m > 0) {
            ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + m, 0));
        }
        else if (m == 0) {
            ret = max(knapsack(pos + 1, m + 1) + d[pos], knapsack(pos + 1, 0));
        }
    }
    else if (m == M) {
        ret = knapsack(pos + m, 0);
    }
 
    return dp[pos][m] = ret;
}
 
int main(void) {
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        d.push_back(a);
        fill(dp[i], dp[i] + M + 1, -1);
    }
    
    cout << knapsack(0, 0) << "\n";
 
    return 0;
    
}

