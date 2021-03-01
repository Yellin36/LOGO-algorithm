#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> people(n+1);
        
        for(int i = 0; i < reserve.size(); i++) {
            people[reserve[i]]++;
        }
        for(int i = 0; i < lost.size(); i++) {
            if(people[lost[i]] == 1) people[lost[i]]--; 
            else if(people[lost[i]-1] == 1) people[lost[i]-1]--;
        	else if(people[lost[i]+1] == 1 && lost[i]+1 != lost[i+1]) 
                people[lost[i]+1]--;
        	else answer--;
        }
        return answer;
}
