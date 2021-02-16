#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;   
    sort(routes.begin(), routes.end());
    int advance = routes[0][1]; 
    
    for(int i=1;i<routes.size();i++){
        if(advance < routes[i][0]){
            answer++; 
            advance = routes[i][1];
        }
        if(advance >= routes[i][1]){
            advance = routes[i][1];
        }
    }
    return answer;
}
