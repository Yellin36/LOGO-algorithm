#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> primeNum;

void findPrimeNumber(int n) {
    int flag = 0;    
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            flag = -1;
            break;
        }
    }
    if(flag == 0)
        primeNum.push_back(n);
}

int findAnswer(int n, string numbers) {
    string tmp = to_string(n);
    int flag = 0, j = 0;
    
    for(int i = 0; i < tmp.size() ; i++) {
        flag = 0;
        for(int j = 0; j < numbers.size(); j++) {
            if(tmp[i] == numbers[j]) {
                flag = -1;
                numbers[j] = 'x';
                break;
            }   
        }
        if(flag == 0)
            return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    string tmp;
    sort(numbers.begin(), numbers.end(), greater<char>());
    int intNum = stoi(numbers);
    
    for(int i = 2; i <= intNum; i++) {
        findPrimeNumber(i);
    }
    
    for(int i = 0; i < primeNum.size(); i++) {
        answer += findAnswer(primeNum[i], numbers);
    }
    
    return answer;
}
