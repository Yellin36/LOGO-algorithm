#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, flag = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < citations.size(); i++) {
        if(i+1 > citations[i]) {
            answer = i;
            flag = -1;
            break;
        }
    }
    
    if(flag == 0)
       return citations.size();
    
    return answer;
}
