#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, e, d, n, k;

        cin >> n >> k;
        vector<vector<int>> building(n);
        vector<int> answer(n, 0);
        vector<int> cnt(n, 0);
        vector<int> time(n);

        for (int i = 0; i < n; i++) {
            cin >> time[i];
        }
        while (k--) {
            cin >> s >> e;
            building[s - 1].push_back(e - 1);
            cnt[e - 1]++;
        }
        cin >> d;

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) q.push(i);
        }
        while (cnt[d - 1] > 0) {
            int c = q.front(); q.pop();
            for (int i : building[c]) {
                answer[i] = max(answer[i], answer[c] + time[c]);

                if (--cnt[i] == 0) q.push(i);
            }
        }
        cout << answer[d - 1] + time[d - 1] << endl;
    }
}
