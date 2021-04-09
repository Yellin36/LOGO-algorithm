#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n, flag;
    
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {          
            if(lost[i] == reserve[j]) {
                lost.erase(lost.begin()+i);
                reserve[j] = -1; i--;
                break;
            }
        }
    }
    
    for(int i = 0; i < lost.size(); i++) {
        flag = 0;
        for(int j = 0; j < reserve.size(); j++) {
            
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j]) {
                flag = -1;
                reserve[j] = -1;
                break;
            }
        }
        
        if(flag == 0)
            answer--;
    }
    
    return answer;
}
