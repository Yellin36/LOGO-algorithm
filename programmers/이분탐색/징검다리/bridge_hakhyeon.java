// 프로그래머스 고득점 kit 이분탐색 - 징검다리
import java.util.*;
public class practice03 {
	public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        Arrays.sort(rocks);
        int left = 0;
        int right = distance;
        int mid = 0;
        while(left <= right) {
        	mid = (left+right) / 2;
        	int prev = 0, removeCount = 0;
        	for(int i = 0; i < rocks.length; i++) {
        		if(rocks[i]-prev < mid) {
        			removeCount++;
        			if(removeCount > n) break;
        		} else 
        			prev = rocks[i];
        	}
        	if(removeCount > n) right = mid - 1;
        	else {
        		answer = Math.max(answer, mid);
        		left = mid + 1;
        	}
        }
        return answer;
    }
}
