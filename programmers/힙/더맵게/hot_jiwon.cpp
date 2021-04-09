#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //올림차순 정렬
    priority_queue<int,vector<int>,greater<int>> food_scovile (scoville.begin(),scoville.end());

    //스코빌 변경
    int tmp = 0;
    while(food_scovile.top() < K){
        if(food_scovile.size() == 1)
            return -1;
        
        tmp = food_scovile.top();
        food_scovile.pop();
        food_scovile.push(food_scovile.top()*2 + tmp);
        food_scovile.pop();
        answer++;
    }

    return answer;
}
