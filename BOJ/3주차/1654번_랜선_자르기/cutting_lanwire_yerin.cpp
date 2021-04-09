#include <iostream>

using namespace std;

long long len[10005];
int main() {
    int n, k;
    long long low = 1, high = 0, answer = 0;

    scanf("%d %d", &k, &n);
    
    for(int i = 0; i < k; i++) {
        scanf("%lld", &len[i]);
        if(high < len[i]) high = len[i];
    }
    while(low <= high) {
        int cnt = 0;
        long long mid = (low + high) / 2;
        
        for(int i = 0; i < k; i++) {
            cnt += len[i] / mid;
        }
        if(cnt >= n) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    printf("%lld", low - 1);
}
