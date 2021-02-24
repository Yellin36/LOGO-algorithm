#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
//distance = 25, rocks = {2 14 11 21 17 24}, n = 3 인경우
    int l = 1, r = distance;    // 거리의 최소, 최대
    vector<int> dif;            // 바위 사이의 거리

//바위 사이 거리 구하기    
    rocks.push_back(0);
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    // 0 2 11 14 17 21 24 25
    for(int i = 1; i < rocks.size(); i++) { // 각 바위 사이의 거리 구하기
        dif.push_back(rocks[i] - rocks[i-1]);
    }  
    // 2 9 3 3 4 3 1

//각 바위 사이의 거리의 최솟값 중에 가장 큰 값 구하기
    while(l < r) {
        int m = (l + r) / 2, rm = 0, sum = 0;   //rm : 제거된 바위의 개수
                                                //sum : 바위가 제거되어 늘어난 사이의 거리
        
        for(int i = 0; i < dif.size(); i++) {
            // (바위를 없앴을 경우의 늘어난)사이 거리가 m보다 큰경우 
            if(m <= dif[i] + sum) sum = 0; // 더 이상 지점을 없앨 수 없음
            
            // m보다 작은 경우 바위를 더 없앨 수 있으므로
            else {      
                rm++;                       // 제거한 다리 수 증가
                sum += dif[i];              // 사라진 지점과 연결된 다리의 거리 증가
            }
        }
        (rm > n) ? r = m - 1: l = m + 1;    // n보다 큰경우 m값을 줄이고 작거나 같은 경우 m값을 키우기 위해
    } 
    // m    for문       rm/ l / r
    // 13   14 11       5 / 1 / 12
    // 6    11 6 7 1    3 / 7 / 12
    // 9    11 10 4     4 / 7 / 8
    // 7    11 10 4     4 / 7 / 6   (종료)
    
    return l - 1;
    // 6
}
