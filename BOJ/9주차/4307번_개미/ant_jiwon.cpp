#include <iostream>
#include <algorithm>

using namespace std;

int l, n;
pair<int, int> result;  //min, max

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        result.first = 0;
        result.second = 0;
        
        cin>>l>>n;
        
        int ant, Min, Max;
        for(int j=0;j<n;j++){
            cin>>ant;
            Min = min(ant, l-ant); //왼, 오
            Max = max(ant, l-ant);

            result.first = max(result.first, Min);
            result.second = max(result.second,Max);
        }
        
        cout<<result.first<<" "<<result.second<<endl;
    }
}

