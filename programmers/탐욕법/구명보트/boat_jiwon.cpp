#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i = 0, j = people.size()-1;
    while(i<=j){
        //최대 2명씩 밖에 탈수 없는게 포인트
        if(people[i] + people[j] <= limit){
            i++;
        }
        j--;answer++;
    }
    return answer;
}
