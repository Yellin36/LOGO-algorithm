// 프로그래머스 고득점 kit 탐욕법(Greedy) - 체육복
public class practice02 {
	public static int solution(int n, int[] lost, int[] reserve) {
        int[] student = new int[n];
		int answer = 0;
        for(int i = 0; i < reserve.length; i++) {
        	student[reserve[i]-1]++;
        }
        for(int i = 0; i < lost.length; i++) {
        	student[lost[i]-1]--;
        }
		for(int i = 0; i < student.length; i++) {
			if(student[i] < 0) {
				if(i != student.length-1 && student[i+1] > 0) {
					student[i]++;
					student[i+1]--;
				} else if(i != 0 && student[i-1] > 0) {
					student[i]++;
					student[i-1]--;
				}
			}
		}
		for(int i = 0; i < student.length; i++) {
			if(!(student[i] < 0))
				answer++;
		}
        return answer;
    }
	public static void main(String[] args) {
		int[] lost = {2,4};
		int[] reserve = {1,3,5};
		System.out.println(solution(5,lost,reserve));
	}
}
