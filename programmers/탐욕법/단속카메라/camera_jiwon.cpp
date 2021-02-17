#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;   
    sort(routes.begin(), routes.end());
    int range = routes[0][1]; 
    
    for(int i=1;i<routes.size();i++){
        if(range < routes[i][0]){
            answer++; 
            range = routes[i][1];
        }
        if(range >= routes[i][1]){
            range = routes[i][1];
        }
    }
    return answer;
}
