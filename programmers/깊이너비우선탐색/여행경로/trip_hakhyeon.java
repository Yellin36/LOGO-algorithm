// 프로그래머스 고득점 kit DFS/BFS - 여행경로
import java.util.*;
public class practice04 {
	boolean[] visited;
	ArrayList<String> answers;
	
	public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        answers = new ArrayList<String>();
        int count = 0;
	DFS(count, "ICN", "ICN", tickets);
	Collections.sort(answers);
	String[] answer = answers.get(0).split(" ");
        return answer;
    }
	
	public void DFS(int count, String present, String answer, String[][] tickets) {
		if(count == tickets.length) {
			answers.add(answer);
			return;
		}
		for(int i = 0; i < tickets.length; i++) {
			if(!visited[i] && tickets[i][0].equals(present)) {
				visited[i] = true;
				DFS(count+1, tickets[i][1], answer+" "+tickets[i][1], tickets);
				visited[i] = false;
			}
		}
		return;
	}
}
