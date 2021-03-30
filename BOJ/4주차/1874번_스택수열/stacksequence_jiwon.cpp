#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    stack<int> s;
    string answer="";
    
    int tmp=0, big =0;
    for(int i=0;i<n;i++){
        cin>>tmp;

        if(big <= tmp){
            for(int j = big+1 ;j<=tmp;j++){
                answer+="+\n";
                s.push(j);
            }
            big = tmp;
            answer+="-\n";
            s.pop();
        }
        else{
            if(s.top() == tmp){
                answer+="-\n";
                s.pop();
            }
            else{
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<answer;
    return 0;
    
}

