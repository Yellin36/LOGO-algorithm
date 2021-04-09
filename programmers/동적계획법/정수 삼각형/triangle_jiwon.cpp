#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i=1;i<triangle.size();i++){
        //양 끝
        triangle[i][0] += triangle[i-1][0];
        triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i].size()-2];
    
        for(int j=1; j<triangle[i].size()-1; j++) {
            if(triangle[i-1][j-1] > triangle[i-1][j])
                triangle[i][j] += triangle[i-1][j-1];
            else
                triangle[i][j] += triangle[i-1][j];
        }
    }
    
    for(int i=0; i<triangle[triangle.size()-1].size(); i++) {
        if(triangle[triangle.size()-1][i] > answer)
            answer = triangle[triangle.size()-1][i];
    }
    
    return answer;
}
