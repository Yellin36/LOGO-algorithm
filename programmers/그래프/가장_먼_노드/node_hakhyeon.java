// 프로그래머스 고득점 kit 그래프 - 가장 먼 노드(실행시간 개선)
import java.util.*;
public class practice07 {
	public int solution(int n, int[][] edge) {
        int answer = 0;
        boolean[] visited = new boolean[n+1];
        ArrayList<Integer>[] list = new ArrayList[n+1];
        for(int i = 1; i <= n; i++) {
			list[i] = new ArrayList<Integer>();
		}
        for(int i = 0; i < edge.length; i++) {
        	list[edge[i][0]].add(edge[i][1]);
        	list[edge[i][1]].add(edge[i][0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> nextNodes = new ArrayList<>();
        queue.add(1);
        visited[0] = visited[1] = true;
        while(true) {
        	answer = queue.size();
        	while(!queue.isEmpty()) {
        		int node = queue.poll();
        		for(int next : list[node]) {
        			if(!visited[next]) {
        				nextNodes.add(next);
        				visited[next] = true;
        			}
        		}
        	}
        	if(nextNodes.isEmpty()) break;
        	queue.addAll(nextNodes);
        	nextNodes.clear();
        }
        return answer;
    }
}
