#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

int main(){
    int N, M; //듣도 보도 못한 사람 수
    scanf("%d %d",&N,&M);
    
    map<string,int> name;
    vector<string> answer;
    
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        name[tmp]++;
    }
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        name[tmp]++;
    }
    
    for(auto n : name){
        if(n.second == 2){
            answer.push_back(n.first);
        }
    }
    sort(answer.begin(), answer.end());
    
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
}

