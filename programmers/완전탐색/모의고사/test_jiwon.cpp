#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int sum[3] = {0}, max = 0;
    int one[] = {1, 2, 3, 4, 5};
    int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i=0; i<answers.size(); i++) {
        if(answers.at(i) == one[i%5]) 
            sum[0]++;
        if(answers.at(i) == two[i%8]) 
            sum[1]++;
        if(answers.at(i) == three[i%10]) 
            sum[2]++;
    }
    for(int i=0; i<3; i++) {
        if(max < sum[i]) 
            max = sum[i];
    }
    for(int i=0; i<3; i++) {
        if(sum[i] == max) 
            answer.push_back(i+1);
    }
    return answer;
}
