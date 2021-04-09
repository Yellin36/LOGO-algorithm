// 프로그래머스 고득점 kit 힙 - 디스크 컨트롤러
import java.util.*;
public class practice01 {
	public static int solution(int[][] jobs) {
		int answer = 0;
		int len = jobs.length;
		int time = 0;
		int idx = 0;
		Queue<int[]> q = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
		
		Arrays.sort(jobs, (o1, o2) -> o1[0] - o2[0]);
		
		while (idx < len || !q.isEmpty()) {
			while (idx < len && jobs[idx][0] <= time)
				q.offer(jobs[idx++]);
			
			if (q.isEmpty())
				time = jobs[idx][0];
			else {
				int[] job = q.poll();
				answer += time - job[0] + job[1];
				time += job[1];
			}
		}
		return answer / len;
	}
	
	public static void main(String[] args) {
		System.out.println(solution(new int[][] { {0,3},
			{1,9}, {2,6} }));
	}
}