#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int result = 0;

int n = 0, m = 0, k = 0, x= 0, y = 0;
int graph[50][50];
vector<int> answer;

bool solution(int x, int y) {

    if (x >= n || y >= m || x < 0 || y < 0) return false;

    if (graph[x][y] == 1) {
        graph[x][y] = 0;

        solution(x - 1, y);
        solution(x, y - 1);
        solution(x + 1, y);
        solution(x, y + 1);
        return true;
    }
    else {
        return false;
    }

    return false;
}
int main() {
    int t = 0;
    cin >> t;
    
    for (int r = 0; r < t; r++)
    {

        cin >> m >> n >> k;
    
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < m; j++)
            {
                graph[i][j] = 0;
            }
        }
        for (int j = 0; j < k; j++)
        {
            cin >> y >> x;
            graph[x][y] = 1;
        }
    
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                
                if (solution(i, j)) {
                    result += 1;
                }
                    
            }
        }
        answer.push_back(result);
        result = 0;
        
    }
    for (int i = 0; i < t; i++)
    {
        cout << answer[i] << endl;
    }
}
