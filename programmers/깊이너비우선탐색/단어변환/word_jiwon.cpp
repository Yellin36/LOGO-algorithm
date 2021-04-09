#include <string>
#include <vector>

using namespace std;
bool visit[51];
int answer = 51;


void DFS(string begin, string target, int cnt, vector<string> words){
    if(begin == target){
        if(answer>cnt)
            answer = cnt;
        return;
    }
    
    for(int i=0;i<words.size();i++){
        if(!visit[i] && begin != words[i]){
            int num = 0;
            for(int j=0;j<begin.length();j++){
                if(begin[j] != words[i][j])
                    num++;
                if(num > 1)
                    break;
            }
            if(num == 1){
                visit[i] = true;
                DFS(words[i],target,cnt+1,words);
                visit[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    DFS(begin,target,0, words);
    
    //반환할 수 없는 경우
    if(answer==51)
        answer = 0;
    return answer;
}
