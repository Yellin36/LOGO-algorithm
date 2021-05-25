// BOJ 2210번: 숫자판 점프
import java.io.*;
import java.util.*;
public class practice07 {
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static int[][] grid;
	static HashSet<String> list;
	static int N;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = 5;
		list = new HashSet<String>();
		grid = new int[N][N];
		String[] input;
		for(int i = 0; i < N; i++) {
			input = br.readLine().split(" ");
			for(int j = 0; j < N; j++) {
				grid[i][j] = Integer.parseInt(input[j]);
			}
		}
		String s = new String();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				Backtrack(i, j, 0, s);
			}
		}
		System.out.println(list.size());
	}
	
	public static void Backtrack(int x, int y, int count, String s) {
		if(count == 6) {
			list.add(s);
			return;
		}
		for(int i = 0; i < 4; i++) {
			int X = dx[i] + x;
			int Y = dy[i] + y;
			if(X < 0 || Y < 0 || X >= N || Y >= N) {
				continue;
			}
			Backtrack(X, Y, count+1, s+grid[x][y]);
		}
	}
}