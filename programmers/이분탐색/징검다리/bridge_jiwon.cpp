#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1, end = distance;
    sort(rocks.begin(), rocks.end());
    
    while(start <= end){
        int mid = (start + end) / 2;
        int cnt = 0;
        int j = -1;
        
        for(int i = 0; i<=(int)rocks.size();i++){
            int len = 0;
            
            if(j == -1)
                len = rocks[i];
            else if(i==(int)rocks.size())
                len = distance - rocks[i];
            else
                len = rocks[i] - rocks[j];
            
            if(len < mid)
                cnt++;
            else
                j = i;
        }
  
        if(cnt > n)
            end = mid - 1;
        else{
            start = mid +1;
            answer = max(answer, mid);
        }
    }
    return answer;
}
