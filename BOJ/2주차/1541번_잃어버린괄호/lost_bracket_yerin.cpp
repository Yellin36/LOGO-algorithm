#include <iostream>
#include <string>
using namespace std;
int main() {
    int sum = 0, cnt = 0, nums[50] = {0};
    char c = 0;
    string num = "";
    
    while(1) {
        scanf("%c", &c);
        if(c == '\n') {				//문장의 끝
            nums[cnt] += stoi(num);
            break;
        }
        if('0' <= c && c <= '9') {		//숫자만들기
            num += c;
            continue;
        }
        nums[cnt] += stoi(num); 
        num = "";
        if(c == '-') cnt++;
    } 
    for(int i =1; i<=cnt; i++) {
        nums[0] -= nums[i];
    }
    printf("%d", nums[0]);
}
