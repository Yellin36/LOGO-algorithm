#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int flag = 0, result = 0;
    
    while(true) {
        if(flag == progresses.size())
            break;
        
        for(int i = 0; i < progresses.size(); i++) {
            if(i == 0 && progresses[i] >= 100 || progresses[i-1] == 0 && progresses[i] >= 100) {
                progresses[i] = 0;
                flag++;
                result++;
            }
        }
        if(flag != 0 && result != 0)
            answer.push_back(result);
        result = 0;
        
        for(int i = 0; i < progresses.size(); i++) {
            if(progresses[i] != 0 && progresses[i] < 100)
                progresses[i] = progresses[i] + speeds[i];
        }
        
        
    }
    
    return answer;
}ude <iostream>
