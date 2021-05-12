#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L;

int solution() {
    queue<pair<int, int>> q;
    priority_queue <int> pq;
    int answer = 0, x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        q.push({ i, x });
        pq.push(x);
    }

    while (!q.empty()) {
        int num = q.front().first;
        int val = q.front().second;
        q.pop();
        if (pq.top() == val) {
            pq.pop();
            answer++;
            if (M == num) {
                break;
            }
        }
        else {
            q.push({ num, val });
        }
    }
    return answer;
}

int main() {
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> N >> M;
        cout << solution() << endl;
    }
}
