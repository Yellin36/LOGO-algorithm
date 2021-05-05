// BOJ 2606번: 바이러스
import java.io.*;
import java.util.*;
public class practice01 {
	static boolean[] visited;
	static ArrayList<ArrayList<Integer>> graph;
	static int count;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int e = Integer.parseInt(br.readLine());
		graph = new ArrayList<>();
		visited = new boolean[n+1];
		for(int i = 0; i <= n; i++) {
			graph.add(new ArrayList<Integer>());
		}
		String str;
		int v1, v2;
		for(int i = 0; i < e; i++) {
			str = br.readLine();
			v1 = Integer.parseInt(str.split(" ")[0]);
			v2 = Integer.parseInt(str.split(" ")[1]);
			graph.get(v1).add(v2);
			graph.get(v2).add(v1);
		}
		count = 0;
		dfs(1);
		System.out.println(count);
	}
	
	static void dfs(int start) {
		visited[start] = true;
		int next;
		for(int i = 0; i < graph.get(start).size(); i++) {
			next = graph.get(start).get(i);
			if(!visited[next]) {
				visited[next] = true;
				count++;
				dfs(next);
			}
		}
	}
}
