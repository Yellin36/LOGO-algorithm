#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int i = 0;
    
    while(i < operations.size()) {
        if(operations[i].substr(0, 1) == "I") {
            string StrToInt = operations[i].substr(2);
            int num = stoi(StrToInt);
            answer.push_back(num);
            sort(answer.begin(), answer.end());
        }
        else if(operations[i].substr(0, 1) == "D"&& !answer.empty()) {
            if(operations[i].substr(2) == "1") {
                answer.pop_back();
            }
            else if(operations[i].substr(2) == "-1") {
                sort(answer.rbegin(), answer.rend());
                answer.pop_back();
                sort(answer.begin(), answer.end());
            }
        }
        i++;
    }
    
    if(answer.empty()) {
        answer.push_back(0); answer.push_back(0);
    }
    
    int max = answer[answer.size()-1];
    int min = answer[0];
    answer.clear();
    answer.push_back(max); answer.push_back(min);
    
    return answer;
}
