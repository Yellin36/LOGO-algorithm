#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>::iterator it;
    int l = lost.size();
    for (int i = 0; i < lost.size(); i++)
    {
        if (find(reserve.begin(), reserve.end(), lost[i]) != reserve.end())
        {
            it = find(reserve.begin(), reserve.end(), lost[i]);
            reserve.erase(it);
            lost[i] = -2;
            l--;
        }
    }
    for (int i = 0; i < lost.size(); i++)
    {
        if (find(reserve.begin(), reserve.end(), lost[i] - 1) != reserve.end())
        {
            it = find(reserve.begin(), reserve.end(), lost[i] - 1);
            reserve.erase(it);
            l--;
        }
        else if (find(reserve.begin(), reserve.end(), lost[i] + 1) != reserve.end())
        {
            it = find(reserve.begin(), reserve.end(), lost[i] + 1);
            reserve.erase(it);
            l--;
        }
    }
    if (l == 0) answer = n;
    else answer = n - l;
    return answer;
}
