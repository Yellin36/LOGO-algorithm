// 프로그래머스 고득점 kit 탐욕법(Greedy) - 조이스틱
public class practice01 {
	public static int solution(String name) {
        int answer = 0;
        int len = name.length();
        int min_move = len-1;
        for(int i = 0; i < len; i++) {
        	// i번째 문자를 보고 위, 아래키 선택
        	answer += Math.min(name.charAt(i)-'A', 'Z'-name.charAt(i)+1);
        	int next = i+1;
        	// 연속된 A가 있는지를 따져 다음 문자열을 판단 
        	while(next < len && name.charAt(next) == 'A')
        		next++;
        	// 내 위치에서 첫 위치로 돌아간 후
        	// A가 연속으로 나오는 지점 다음을 끝에서 계산하여
        	// 기존에 움직인 횟수와 비교
        	min_move = Math.min(min_move, i+len-next+i);
        }
        answer += min_move;
        return answer;
    }
	
	public static void main(String[] args) {
		System.out.println(solution("JAZ"));
		System.out.println(solution("JEROEN"));
		System.out.println(solution("JAN"));
		System.out.println(solution("CAQF"));
	}
}
