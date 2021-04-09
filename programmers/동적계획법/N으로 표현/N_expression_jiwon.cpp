#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 9;

void sol(int N,int number,int count,int current_num){
    if(count >= 9)
        return;
    if(number == current_num){
        answer = min(count,answer);
        return;
    }
    
    
    int tmp_num=0;
    for(int i=0;i<9;i++){  //n이 1~9이므로
        tmp_num = tmp_num*10 + N;
        sol(N,number,count+1+i,current_num+tmp_num);
        sol(N,number,count+1+i,current_num-tmp_num);
        sol(N,number,count+1+i,current_num*tmp_num);
        sol(N,number,count+1+i,current_num/tmp_num);
    }
}

int solution(int N, int number) {
    sol(N,number,0,0);
    
    if(answer >= 9)
        return -1;
    return answer;
}
