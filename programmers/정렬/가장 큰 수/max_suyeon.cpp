#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortNum(string num1, string num2) {
    if(num1+num2 > num2+num1)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    for(int i = 0; i < numbers.size(); i++)
        tmp.push_back(to_string(numbers[i]));
    
    sort(tmp.begin(), tmp.end(), sortNum);

    for(int i = 0; i < tmp.size(); i++)
        answer += tmp[i];
    
    if(answer[0] == '0')
        return "0";
    
    return answer;
}
