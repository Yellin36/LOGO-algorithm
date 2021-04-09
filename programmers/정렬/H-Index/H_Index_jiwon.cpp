#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(),greater<>());
    vector<int> tmp;
     for(int i=0;i<citations.size();i++){
         tmp.push_back(min(citations[i],i+1));
    }
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]>answer)
            answer = tmp[i];
    }
    
    return answer;
}
