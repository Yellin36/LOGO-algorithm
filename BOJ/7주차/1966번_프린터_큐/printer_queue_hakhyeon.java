// BOJ 1966번: 프린터 큐
import java.io.*;
import java.util.*;
public class practice01 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			String str = br.readLine();
			int n = Integer.parseInt(str.split(" ")[0]);
			int location = Integer.parseInt(str.split(" ")[1]);
			int priorities[] = new int[n];
			String input = br.readLine();
			for(int j = 0; j < priorities.length; j++) {
				priorities[j] = Integer.parseInt(input.split(" ")[j]);
			}
			System.out.println(solution(priorities, location));
		}
	}
	static int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Printer> q = new LinkedList<>();
		for (int i = 0; i < priorities.length; i++) {
			q.offer(new Printer(i, priorities[i]));
		}
		while (!q.isEmpty()) {
			boolean flag = false;
			int com = q.peek().priorities;
			for (Printer p : q) {
				if (com < p.priorities) {
					flag = true;
				}
			}

			if (flag) {
				q.offer(q.poll());
			} else {
				if (q.poll().location == location) {
					answer = priorities.length - q.size();
				}
			}
		}
        return answer;
    }
	static class Printer {
		int location;
		int priorities;
		Printer(int location, int priorities) {
			this.location = location;
			this.priorities = priorities;
		}
	}
}