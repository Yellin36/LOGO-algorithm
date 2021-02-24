// 프로그래머스 고득점 kit 탐욕법(Greedy) - 섬 연결하기
import java.util.*;
public class practice03 {
	public int solution(int n, int[][] costs) {
        int answer = 0;
        Arrays.sort(costs, (o1, o2)->{
        	return o1[2]-o2[2];
        });
        int[] parent = new int[n];
        for(int i = 0; i < n; i++)
        	parent[i] = i;
        for(int[] cost : costs) {
        	int from = cost[0];
        	int to = cost[1];
        	int value = cost[2];
        	if(isConnect(parent, from, to)) continue;
        	else {
        		answer += value;
        		union(parent, from, to);
        	}
        }
        return answer;
    }
	
	public static void union(int[] parent, int from, int to) {
		from = getParent(parent, from);
		to = getParent(parent, to);
		if(from < to)
			parent[to] = from;
		else
			parent[from] = to;
	}
	public static boolean isConnect(int[] parent, int from, int to) {
		from = getParent(parent, from);
		to = getParent(parent, to);
		if(from == to) return true;
		else return false;
	}
	public static int getParent(int[] parent, int node) {
		if(parent[node] == node) return node;
		return getParent(parent, parent[node]);
	}
}
