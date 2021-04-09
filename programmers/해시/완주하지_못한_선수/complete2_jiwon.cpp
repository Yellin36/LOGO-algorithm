#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> completion_map;
    for(auto name : completion){
        if(!completion_map.count(name))
            completion_map.insert(make_pair(name, 1));
        else
            completion_map[name]++;
    }
    

    for(auto name : participant){
        if(completion_map.count(name))
            completion_map[name]--;
        else
            return name;
        if(completion_map[name] == -1)
            return name;
    }
    return answer;
}
