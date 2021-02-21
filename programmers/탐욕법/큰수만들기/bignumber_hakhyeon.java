// 프로그래머스 고득점 kit 탐욕법(Greedy) - 큰 수 만들기
public class practice04 {
	public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();
        int index = 0;
        char max;
        if(number.charAt(0) == '0') return "0";
        for(int i = 0; i < number.length()-k; i++) {
        	max = '0';
        	for(int j = index; j <= k+i; j++) {
        		if(max < number.charAt(j)) {
        			max = number.charAt(j);
        			index = j + 1;
        		}
        	}
        	answer.append(max);
        }
        return answer.toString();
    }
}
