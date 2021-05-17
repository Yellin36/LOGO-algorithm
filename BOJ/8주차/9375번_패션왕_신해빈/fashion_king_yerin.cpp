#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int t, n;
    string category, clothes;

    cin >> t;
    while (t--) {
        int answer = 1;
        map<string, int> cnt;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> clothes >> category;
            cnt[category]++;
        }
        for (auto i : cnt) {
            answer *= (i.second + 1);
        }
        cout << answer - 1 << endl;
    }
}
