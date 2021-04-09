#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int i=0;

    priority_queue<pair<int, int>,vector<pair<int, int>>,compare> ready_queue;
    
    //jobs를 시간 순서대로 input한다는 말이 없으므로 정렬을 시켜준다.
    sort(jobs.begin(),jobs.end());
    
    while(i<jobs.size() || !ready_queue.empty()){
        if(i<jobs.size() && jobs[i][0]<=time){
            ready_queue.push(make_pair(jobs[i][0], jobs[i++][1]));
            continue;
        }
        if(ready_queue.empty()){
            time = jobs[i][0];
        }
        else{
            time += ready_queue.top().second;
            answer += time - ready_queue.top().first;
            ready_queue.pop();
        }
    }
    
    return answer/jobs.size();
}
