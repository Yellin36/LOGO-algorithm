// 프로그래머스 고득점 kit 정렬 - K번째수
import java.util.*;
public class practice02 {
	public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int[] tmp;
        for(int i = 0; i < commands.length; i++) {
        	int start = commands[i][0];
        	int end = commands[i][1];
        	tmp = new int[end-start+1];
        	for(int j = 0; j < tmp.length; j++) {
        		tmp[j] = array[start + j - 1];
        	}
        	Arrays.sort(tmp);
        	answer[i] = tmp[commands[i][2] - 1];
        }
        return answer;
    }
	public static void main(String[] args) {
		int[] array = {1,5,2,6,3,7,4};
		int[][] commands = {{2,5,3},{4,4,1},{1,7,3}};
		int[] answer = solution(array, commands);
		for(int i = 0; i < answer.length; i++)
			System.out.print(answer[i] + " ");
	}
}
