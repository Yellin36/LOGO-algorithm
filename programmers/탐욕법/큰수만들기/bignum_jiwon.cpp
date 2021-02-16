#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int tmp = -1;
    
    for(int i=(int)number.length()-k;i>0;i--){
        char max = '0';
        for(int j = tmp+1; j<=number.length() -i;j++){
            if(max < number[j]){
                max = number[j];
                tmp = j;
                //9보다 큰 수는 없으므로 예외처리하여 시간줄이기
                if(number[j] == '9')
                    break;
            }
        }
        answer+=max;
    }
    return answer;
}
