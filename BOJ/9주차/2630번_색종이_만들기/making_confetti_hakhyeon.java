// BOJ 2630번: 색종이 만들기
import java.io.*;
import java.util.*;
public class practice02 {
	static int white = 0;
	static int blue = 0;
	static int[][] grid;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		grid = new int[N][N];
		StringTokenizer st;
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for(int j = 0; j < N; j++) {
				grid[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		partition(0, 0, N);
		
		System.out.println(white);
		System.out.println(blue);
	}

	public static void partition(int row, int col, int size) {
		if(check(row, col, size)) {
			if(grid[row][col] == 0) {
				white++;
			} else {
				blue++;
			}
			return;
		}
		int newSize = size / 2;
		
		partition(row, col, newSize);
		partition(row, col+newSize, newSize);
		partition(row+newSize, col, newSize);
		partition(row+newSize, col+newSize, newSize);
		
	}

	public static boolean check(int row, int col, int size) {
		int color = grid[row][col];
		for(int i = row; i < row+size; i++) {
			for(int j = col; j < col+size; j++) {
				if(grid[i][j] != color)
					return false;
			}
		}
		return true;
	}
}