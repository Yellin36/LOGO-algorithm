#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<pair<int, string>> v;
    
    for(int i=0; i<genres.size();i++){
        m[genres.at(i)]+=plays.at(i);
    }
    for(auto p : m)
        v.push_back(make_pair(p.second, p.first));
    sort(v.begin(), v.end());
    
    while(v.size()){
        vector<pair<int, int>> tmp;
        for(int i=0;i<genres.size();i++){
            if(v.back().second == genres.at(i))
                tmp.push_back(make_pair(plays.at(i),i));
        }
        sort(tmp.begin(), tmp.end());
        vector<int> arr;
        for(int i = (int)tmp.size() -1;i>=0;i--){
            if(tmp.back().first == tmp.at(i).first)
                arr.push_back(tmp.at(i).second);
        }
        if(arr.size()>=2){
            answer.push_back(arr.back());
            arr.pop_back();
            answer.push_back(arr.back());
        }
        else{
            answer.push_back(tmp.back().second);
        tmp.pop_back();
        if(tmp.size())
            answer.push_back(tmp.back().second);
        }
        v.pop_back();
    }
    
    return answer;
}
