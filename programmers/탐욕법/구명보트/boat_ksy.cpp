#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, l = 0;
    int sum = 0;
    int r = people.size()-1;
    sort(people.begin(), people.end(), greater<int>());
    while (l < r)
    {
        sum = people[l] + people[r];
        if (sum > limit) {
            l++;
        }
        else
        {
            l++; r--;
        }
        answer++;
    }
    if (l == r) answer++;
    return answer;

}
