#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, len, n, fast, late, x, resultF, resultL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    //input
    cin >> T;
    while (T--) {
        resultF = 0, resultL = 0;
        cin >> len >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;

            fast = min(x, len - x);
            late = max(x, len - x);

            resultF = max(fast, resultF);
            resultL = max(late, resultL);
        }
        cout << resultF << " " << resultL << endl;
    }
}
