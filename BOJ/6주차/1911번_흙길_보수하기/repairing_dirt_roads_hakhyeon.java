// BOJ 1911번: 흙길 보수하기
import java.io.*;
import java.util.*;
public class practice02 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		
		int[][] puddle = new int[N][2];
		for(int i = 0; i < N; i++) {
			String str = br.readLine();
			puddle[i][0] = Integer.parseInt(str.split(" ")[0]);
			puddle[i][1] = Integer.parseInt(str.split(" ")[1]);
		}
		Arrays.sort(puddle, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[0] == o2[0])
					return Integer.compare(o1[1], o2[1]);
				return Integer.compare(o1[0], o2[0]);
			}
		});
		int answer = 0;
		int range = 0;
		for(int i = 0; i < N; i++) {
			if(puddle[i][0] > range) {
				range = puddle[i][0];
			}
			if(puddle[i][1] >= range) {
				while(puddle[i][1] > range) {
					range += L;
					answer++;
				}
			}
		}
		System.out.println(answer);
	}
}
