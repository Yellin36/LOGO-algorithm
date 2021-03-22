// BOJ 1261번: 알고스팟
import java.io.*;
import java.util.*;
public class practice05 {
	static class Point implements Comparable<Point> {
		int x; int y; int count;
		Point(int x, int y, int count) {
			this.x = x;
			this.y = y;
			this.count = count;
		}
		@Override
		public int compareTo(Point o) {
			return count - o.count;
		}
	}
	
	static int[] X = {-1, 0, 1, 0};
	static int[] Y = {0, 1, 0, -1};
	static int N, M;
	static int[][] grid; // 입력값을 받는 맵에 해당합니다.
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		grid = new int[N+1][M+1];
		for(int i = 1; i <= N; i++) {
			String[] input = br.readLine().split("");
			for(int j = 1; j <= M; j++) {
				grid[i][j] = Integer.parseInt(input[j-1]);
			}
		}
		int answer = bfs(1, 1);
		bw.write(answer + "\n");
		bw.flush();
		bw.close();
		br.close();
	}
	
	public static int bfs(int x, int y) {
		// 우선순위 큐를 사용한 이유는 poll 연산의 결과에 해당하는 객체의 count 값이 결국 가장 작기 때문
		// 내부적 구조는 오름차순 정렬의 상태(지난번 programmers 이중 우선순위 큐 문제 참고)
		PriorityQueue<Point> pq = new PriorityQueue<>();
		pq.offer(new Point(x, y, 0));
		boolean[][] visit = new boolean[N+1][M+1];
		int dx, dy;
		
		while(!pq.isEmpty()) {
			Point p = pq.poll();
			
			if(p.x == N && p.y == M) { // 해당 위치에 도달하게 되면 그 카운트 값을 리턴
				return p.count;
			}
			for(int i = 0; i < 4; i++) {
				dx = p.x + X[i];
				dy = p.y + Y[i];
				if(dx < 1 || dy < 1 || dx > N || dy > M) { // 범위를 벗어나는 예외
					continue;
				}
				if(!visit[dx][dy] && grid[dx][dy] == 0) { // 벽이 없다면
					visit[dx][dy] = true;
					pq.offer(new Point(dx, dy, p.count)); // count 변화 없이 움직임
				}
				if(!visit[dx][dy] && grid[dx][dy] == 1) { // 벽이 있다면
					visit[dx][dy] = true;
					pq.offer(new Point(dx, dy, p.count + 1)); // count 1 증가
				}
			}
		}
		return 0;
	}

}
