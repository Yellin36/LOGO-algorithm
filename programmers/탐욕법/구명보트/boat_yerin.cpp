#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0, i = 0, j = people.size() - 1;
    sort(people.begin(), people.end(), compare);
    
    while(i<=j) {
        if(i == j) { 
            answer++;
            break;
        }
        if(people[i] + people[j] <= limit) {
            i++; j--;
        }
        else i++;
        answer++;
    }
    return answer;
}
