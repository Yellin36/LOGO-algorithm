#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> map[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int length[20001];
    int visited[20001];

    memset(length, 0, sizeof(length));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < edge.size(); i++)
    {
        map[edge[i][0]].push_back(edge[i][1]);
        map[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int s = q.size();
        for (int k = 0; k < s; k++)
        {
            int now = q.front();
            q.pop();
            length[now] = cnt;
            for (int i = 0; i < map[now].size(); i++)
            {
                if (visited[map[now][i]] == 1)
                    continue;
                visited[map[now][i]] = 1;
                q.push(map[now][i]);
            }

        }
        cnt++;
    }
    int find_max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (length[i] > find_max)
            find_max = length[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (length[i] == find_max)
            answer++;
    }
    return answer;
}

// 혼자서 풀지 못한 문제 ㅠㅠ
