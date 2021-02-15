// 프로그래머스 고득점 kit 완전탐색 - 카펫
import java.util.*;
public class practice03 {
	public Vector<Integer> solution(int brown, int yellow) {
		Vector<Integer> answer = new Vector<Integer>();
		int total = brown + yellow;
		for(int height = 3; height <= total; height++) {
			int width = total / height;
			if(width >= height && (width-2)*(height-2) >= yellow) {
				answer.add(width);
				answer.add(height);
				return answer;
			}
		}
	    return answer;
	}
}
