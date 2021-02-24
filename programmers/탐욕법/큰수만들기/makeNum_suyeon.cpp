#include <string>
#include <vector>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
    int findnum = 0;
    
    for(int i = 0; i < number.size() - k; i++) {
        int maxIdx = findnum;
        char max = number[findnum];
        
        for(int j = findnum; j <= k + i; j++) {
            if(max < number[j]) {
                max = number[j];
                maxIdx = j;
            }
        }
        findnum = maxIdx + 1;
        answer += max;
    }
 
    return answer;
}
