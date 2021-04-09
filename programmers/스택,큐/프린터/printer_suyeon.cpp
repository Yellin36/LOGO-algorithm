#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max(int sequence, vector<int> priorities, int size) {   //priorities 벡터 내에서 최
	int maxNum = priorities[sequence];                      //대값을 찾는 함수
	for (int i = sequence; i < size; i++) {
		if (maxNum < priorities[i]) {
			maxNum = priorities[i];
		}
	}
	return maxNum;
}

int solution(vector<int> priorities, int location) {
    
	int sequence = 0;   //
	int flag = true, result = 0;

	while (flag) {
		int size = priorities.size();
		int maxNum = max(sequence, priorities, size);
		for (int i = sequence; i < size; i++) {
			if (priorities[sequence] < maxNum) {
				priorities.push_back(priorities[sequence]);
                
                if(location == 0 || (i == location && priorities[sequence-1] == 0))
                    location = priorities.size()-1;
                
                priorities[sequence] = 0;
			}
			else if (maxNum == priorities[sequence]) {
				priorities[sequence] = 0;
				result++;
                if(i == location) {
                    flag = false;
                    break;
                }
			}
            break;
		}

		sequence++;
	}
	return result;
}
