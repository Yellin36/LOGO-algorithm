// BOJ 1613번: 역사
import java.io.*;
import java.util.*;
public class practice05 {
	static int n, k, s;
	static int arr[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		arr = new int[n+1][n+1];
		while(k-- > 0) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			arr[u][v] = -1;
			arr[v][u] = 1;
		}
		
		floyd_warshall();
		
		s = Integer.parseInt(br.readLine());
		while(s-- > 0) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			System.out.println(arr[u][v]);
		}
	}

	public static void floyd_warshall() {
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(arr[i][j] == 0) {
						if(arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
						else if(arr[i][k] == -1 && arr[k][j] == -1) arr[i][j] = -1;
					}
				}
			}
		}
	}
}