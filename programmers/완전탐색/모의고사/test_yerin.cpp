#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3] = {0}, max = 0,
        one[5] = {1, 2, 3, 4, 5},
        two[8] = {2, 1, 2, 3, 2, 4, 2, 5},
        three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == one[i % 5]) cnt[0]++;
        if(answers[i] == two[i % 8]) cnt[1]++;
        if(answers[i] == three[i % 10]) cnt[2]++;
    }
    for(int i = 0; i < 3; i++)
        if(max < cnt[i]) max = cnt[i];
    
    if(cnt[0] == max) answer.push_back(1);
    if(cnt[1] == max) answer.push_back(2);
    if(cnt[2] == max) answer.push_back(3);
    
    return answer;
}
