#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int top = 0, cnt = 0, progress;
    
    for(int i=0; i<progresses.size(); i++) {
        progress = (99 - progresses[i]) / speeds[i] + 1;
        
        if(progress > top) {
            if(top) answer.push_back(cnt);
            top = progress;
            cnt = 1;
        }
        else cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}
