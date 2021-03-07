// 프로그래머스 고득점 kit 이분탐색 - 입국심사
import java.util.*;
public class practice02 {
	public long solution(int n, int[] times) {
		Arrays.sort(times);
		long min = 1;
		long max = (long)times[times.length - 1] * n;
		long mid = 0;
		long sum;
        long answer = max;
        while(min <= max) {
        	sum = 0;
        	mid = (min+max)/2; // 중앙값: 심사위원에게 주어진 시간
        	for(int i = 0; i < times.length; i++) {
        		sum += mid / times[i];
        	}
        	if(sum < n) // 대기 중인 사람보다 더 적게 처리하면 mid가 커져야 함.
        		min = mid+1;
        	else {	// 대기 중인 사람보다 더 많이 처리하면 mid를 줄일 수 있다.
        		max = mid-1;
        		answer = mid;
        	}
        }
        return answer;
    }
}
