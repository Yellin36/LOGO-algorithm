// BOJ 3190번: 뱀
import java.io.*;
import java.util.*;
public class practice07 {
	public static class Point {
		int x; int y;
		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
	public static int[] dx = {0,1,0,-1};
	public static int[] dy = {-1,0,1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] grid = new int[n+2][n+2];
		// 테두리 초기화
		for(int i = 0; i < grid.length; i++) {
			grid[i][0] = grid[0][i] = grid[n+1][i] = grid[i][n+1] = 1;
		}
		int k = Integer.parseInt(br.readLine());
		for(int i = 0; i < k; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int x_apple = Integer.parseInt(st.nextToken());
			int y_apple = Integer.parseInt(st.nextToken());
			grid[x_apple][y_apple] = 2;
		}
		Map<Integer, String> rotation = new HashMap<>();
		int l = Integer.parseInt(br.readLine());
		for(int i = 0; i < l; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int x = Integer.parseInt(st.nextToken());
			String c = st.nextToken();
			rotation.put(x, c);
		}
		
		int dir = 1;
		int time = 0;
		Deque<Point> snake = new ArrayDeque<>();
		snake.add(new Point(1,1));
		while(true) {
			time++;
			Point head = snake.peekLast();
			int nX = head.x + dx[dir];
			int nY = head.y + dy[dir];
			if(grid[nY][nX] == 1)
				break;
			if(grid[nY][nX] != 2) {
				Point tail = snake.poll();
				grid[tail.y][tail.x] = 0;
			}
			grid[nY][nX] = 1;
			snake.addLast(new Point(nY, nX));
			if(rotation.containsKey(time)) {
				dir = (rotation.get(time).equals("D")) ? (dir+1) % 4 : (dir+3) % 4;
			}
		}
		System.out.println(time);
	}
}
