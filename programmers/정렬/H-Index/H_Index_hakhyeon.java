// 프로그래머스 고득점 kit 정렬 - H-Index
import java.util.*;
public class practice05 {
	public int solution(int[] citations) {
		Integer[] conv = Arrays.stream(citations)
				.boxed()
				.toArray(Integer[]::new);
		Arrays.sort(conv, Collections.reverseOrder());
        int answer = 0;
        int[] temp = new int[citations.length];
        for(int i = 0; i < citations.length; i++) {
        	temp[i] = Math.min(conv[i], i+1);
        }
        for(int i = 0; i < temp.length; i++) {
        	if(temp[i] > answer)
        		answer =  temp[i];
        }
        return answer;
    }
}
