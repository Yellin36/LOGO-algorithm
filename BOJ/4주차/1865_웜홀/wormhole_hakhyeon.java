// BOJ 1865번: 웜홀
import java.io.*;
import java.util.*;
public class practice07 {
	static class Edge {
		int start, end, time;
		Edge(int start, int end, int time) {
			this.start = start;
			this.end = end;
			this.time = time;
		}
	}
	static final int INF = (int)1e9;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int TC = Integer.parseInt(br.readLine());
		while(TC-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());
			
			List<Edge> edgeList = new ArrayList<>();
			for(int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int S = Integer.parseInt(st.nextToken());
				int E = Integer.parseInt(st.nextToken());
				int T = Integer.parseInt(st.nextToken());
				edgeList.add(new Edge(S, E, T));
				edgeList.add(new Edge(E, S, T));
			}
			
			for(int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int S = Integer.parseInt(st.nextToken());
				int E = Integer.parseInt(st.nextToken());
				int T = Integer.parseInt(st.nextToken());
				edgeList.add(new Edge(S, E, T * (-1)));
			}
			
			int[] distance = new int[N+1];
			Arrays.fill(distance, INF);
			distance[1] = 0;
			boolean check = false;
			
			outerloop:
			for(int i = 1; i <= N; i++) {
				check = false;
				for(Edge edge : edgeList) {
					if(distance[edge.end] > distance[edge.start] + edge.time) {
						distance[edge.end] = distance[edge.start] + edge.time;
						check = true;
						if(i == N) {
							check = true;
							break outerloop;
						}
					}
				}
				if(!check) break;
			}
			sb.append((check ? "YES" : "NO") + "\n");
		}
		System.out.println(sb);
	}
}
