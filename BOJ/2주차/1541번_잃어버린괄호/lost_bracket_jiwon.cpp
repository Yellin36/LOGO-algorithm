#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;


int main(){
    string math;
    cin>>math;
    
    int answer = 0;
    string num="";
    bool minus = false;
    
    for(int i=0;i<math.size();i++){
        if(math[i] == '+' || math[i] == '-' || math[i] == '\n'){
            if(minus){
                answer -= stoi(num);
            }
            else{
                answer += stoi(num);
            }
            
            if(math[i] == '-'){
                minus = true;
            }
            num = "";
        }
        else{
            num+=math[i];
        }
    }
    
    answer = minus? answer-stoi(num): answer+stoi(num);
    cout<<answer<<endl;
    
}

