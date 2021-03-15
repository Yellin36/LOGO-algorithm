#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    vector<string> v;
    vector<string> answer;
    string x;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (binary_search(v.begin(), v.end(), x)) {
            answer.push_back(x);
        }
    }
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}
