// 프로그래머스 고득점 kit 정렬 - 가장 큰 수
import java.util.*;
public class practice03 {
	public static String solution(int[] numbers) {
        String[] temp = new String[numbers.length];
        String answer;
        for(int i = 0; i < numbers.length; i++) {
        	temp[i] = Integer.toString(numbers[i]);
        }
        Arrays.sort(temp, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return ((o2 + o1).compareTo(o1 + o2));
			}
		});
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < temp.length; i++)
        	sb.append(temp[i]);
        answer = sb.toString();
        if(answer.charAt(0) == '0') // input이 전부 0인 경우 예외 발생합니다.
        	return "0";
        return answer;
	}
	
	public static void main(String[] args) {
		int[] numbers = {3, 30, 34, 5, 9};
		String answer = solution(numbers);
		System.out.println(answer);
	}
}
