#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int cnt;
    
    for(int i = 0; i < prices.size(); i++) {
        cnt = 1;
        if(i == prices.size() - 1)
            cnt = 0;
        int stock = prices[i];
        
        for(int j = i+1; j < prices.size()-1; j++) {
            if(stock <= prices[j])
                cnt++;
            else
                break;
        }
        
        answer.push_back(cnt);
    }
    return answer;
}
