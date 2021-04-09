#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clo;
    
    for(int i=0; i<clothes.size(); i++) 
        clo[clothes[i][1]]++;
    for(auto i : clo) 
        answer *= (i.second + 1);
    
    return answer - 1;
}
