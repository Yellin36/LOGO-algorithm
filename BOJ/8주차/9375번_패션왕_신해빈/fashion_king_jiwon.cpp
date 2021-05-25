#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        int answer = 1;
        map<string, int> combination;
        
        int n;
        cin>>n;
        string clothes, kind;
        
        for(int i=0;i<n;i++){
            cin>>clothes>>kind;
            combination[kind]++;
        }
        
        for(auto m : combination)
            answer *= m.second + 1;
        
        cout<<answer-1<<endl;
        
    }
}

