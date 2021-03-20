// BOJ 1012번: 유기농 배추
import java.io.*;
import java.util.*;
public class practice01 {
	public static int numCabbage(char[][] grid) { // 배추 지렁이 개수세기
		int count = 0;
		for(int i = 0; i < grid.length; i++) {
			for(int j = 0; j < grid[i].length; j++) {
				if(grid[i][j] == '1') {
					dfs(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}
	public static void dfs(char[][] grid, int x, int y) {
		grid[x][y] = '#'; // 방문한 노드 초기화
		if(x < grid.length-1 && grid[x+1][y] == '1') // 상
			dfs(grid, x+1, y);
		if(x > 0 && grid[x-1][y] == '1') // 하
			dfs(grid, x-1, y);
		if(y > 0 && grid[x][y-1] == '1') // 좌
			dfs(grid, x, y-1);
		if(y < grid[x].length-1 && grid[x][y+1] == '1') // 우
			dfs(grid, x, y+1);
	}
	
	static int M, N, K;
	static StringBuilder sb = new StringBuilder(); 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int answer = 0;
		for(int a = 0; a < T; a++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			while(st.hasMoreTokens()) {
				M = Integer.parseInt(st.nextToken());
				N = Integer.parseInt(st.nextToken());
				K = Integer.parseInt(st.nextToken());
			}
			char[][] grid = new char[M][N];
			for(int i = 0; i < grid.length; i++) { // grid 초기화
				for(int j = 0; j < grid[i].length; j++) {
					grid[i][j] = '0';
				}
			}
			for(int i = 0; i < K; i++) {
				StringTokenizer st1 = new StringTokenizer(br.readLine()," ");
				int X = Integer.parseInt(st1.nextToken());
				int Y = Integer.parseInt(st1.nextToken());
				grid[X][Y] = '1';
			}

			answer = numCabbage(grid);
			sb.append(answer +"\n");
		}
		System.out.println(sb);
	}
}
