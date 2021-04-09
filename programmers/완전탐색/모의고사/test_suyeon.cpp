#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> first = {1, 2, 3, 4, 5}; 
vector<int> second = {2, 1, 2, 3, 2, 4, 2 ,5};
vector<int> third = {3, 3 ,1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> sum, answer; 
    int n1 = 0, n2 = 0, n3 = 0;
    int j = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    
    sum.push_back(0), sum.push_back(0), sum.push_back(0);
    
    while(j < answers.size()) {
        if(n1 == 5) n1 = 0;
        if(n2 == 8) n2 = 0;
        if(n3 == 10) n3 = 0;
        
        if(answers[j] == first[n1]) sum[0]++;
        if(answers[j] == second[n2]) sum[1]++;
        if(answers[j] == third[n3]) sum[2]++;
        
        j++; n1++; n2++; n3++;
    }
    
    int max = sum[0], maxNum = 0;
    for(int i = 1; i < 3; i++) {
        if(max < sum[i]) {
            max = sum[i];
            maxNum = i;
        }
    }
    
    for(int i = 0; i < 3; i++) {
        if(max == sum[i]) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
