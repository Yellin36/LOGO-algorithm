#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> tmp;
    
    
    while(operations.size()){
        if(tmp.size() && operations.front().substr(0,2)!="I "){
            if(operations.front().compare("D -1")){
                tmp.pop_back();
            }
            else if (operations.front().compare("D 1")){
                tmp.erase(tmp.begin());
            }
        }
        else(operations.front().substr(0,2)=="I "){
            tmp.push_back(stoi(operations.front().substr(2)));
        }
        operations.erase(operations.begin());
        sort(tmp.begin(), tmp.end());
    }
    
    
    
    if(tmp.size()){
        answer.push_back(tmp.back());
        answer.push_back(tmp.front());
    
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
