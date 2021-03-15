#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

int N, M;
int arr[10001][501];
vector<int> run;

int solution(int pos, int G){ //위치, 지침지수
    if (pos == N - G) return 0;    // 수업 시작하기 전에 무조건 지침지수가 0이 되어야함
    if (pos > N - G) return -99999999;
    if (arr[pos][G] >= 0) return arr[pos][G];
    
    
    int ans = 0;
    if(G < M){
        if(G > 0){ //달렸을때, 쭉 쉬었을때
            ans = max(solution(pos+1,G+1) + run[pos], solution(pos+G,0));  //run or norun
        }
        else if(G == 0){ //0이면 한칸 앞으로 가거나 쉴 수 있음
            ans = max(solution(pos+1,G+1) + run[pos], solution(pos+1,0));
            
        }
    }
    //지침지수 == M이면 0까지 다 쉬어야함
    else if(G == M){
        ans = solution(pos + G, 0);
    }
    
    return arr[pos][G] = ans;
}


int main(){
    scanf("%d %d",&N, &M);
    
    //arr을 초기화해줘야함 -1로
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        run.push_back(a);
        fill(arr[i], arr[i] + M + 1, -1);
    }
    cout<<solution(0,0)<<endl;
    
}



