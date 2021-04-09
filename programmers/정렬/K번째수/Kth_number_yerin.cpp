#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++) {
        int target = commands[i][2]-1;
        vector<int>::iterator start = array.begin()+commands[i][0]-1,
                                end = array.begin()+commands[i][1];
        vector<int> tmp(start, end);
        
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[target]);
    }
    return answer;
}
