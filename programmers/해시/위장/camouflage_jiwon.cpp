#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> combination;
    
    for(auto v : clothes)
        combination[v[1]]++;
    
    for(auto m : combination)
        answer *= m.second + 1;
    
    return answer-1;
}
