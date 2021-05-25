#include <iostream>
#include <map>
using namespace std;

map<string, int> cloths;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int answer = 1;
    string x, kind;

    cin >> n;

    for (int t = 0; t < n; t++)
    {
        cin >> m;
        
        for (int i = 0; i < m; i++)
        {
            cin >> x >> kind;
            cloths[kind]++;
        }
        map<string, int>::iterator iter;
        for (iter = cloths.begin(); iter != cloths.end(); iter++    )
        {
            answer *= iter->second + 1;
        }
        answer--;
        cout << answer << endl;
        cloths.erase(cloths.begin(), cloths.end());
        answer = 1;
    }
}
