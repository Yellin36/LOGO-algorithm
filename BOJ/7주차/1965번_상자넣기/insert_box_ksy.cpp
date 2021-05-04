#include <iostream>
#include <algorithm>
using namespace std;

int box[1001];
int dp[1001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (box[j] < box[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    sort(dp+1, dp + (n+1));
    cout << dp[n] << endl;
    return 0;
}
