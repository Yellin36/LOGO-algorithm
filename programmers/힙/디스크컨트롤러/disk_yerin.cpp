#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, i = 0;
    bool comp = false;
    vector<pair<int, int>> q;
    
    sort(jobs.begin(), jobs.end());

    while(i < jobs.size() || !q.empty()) {
        if(i < jobs.size() && jobs[i][0] <= time) {
            q.push_back({jobs[i][0], jobs[i][1]});
            i++; comp = true;
            continue;
        }
        if(i < jobs.size() && q.empty()) {
            q.push_back({jobs[i][0], jobs[i][1]});
            time = jobs[i][0];
            i++;
        }
        else {
            if(comp) {
                sort(q.begin(), q.end(), compare); 
                comp = false;
            }
            time += q.back().second;
            answer += time - q.back().first;
            q.pop_back();
        }
    }
    return answer/jobs.size();
}
