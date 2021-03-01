#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, last = people.size()-1, flag = 0;
    sort(people.begin(), people.end());
    
    for(int i = 0; i < people.size();) {
        answer++;
        if(people[i] + people[last] <= limit) {
            last--; i++;
        }
        else {
            last--;
        }
        if(i > last)
            break;
    }
    
    return answer;
}
