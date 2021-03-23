// BOJ 1654번: 랜선 자르기
import java.io.*;
import java.util.*;
public class practice06 {
	public static int[] list;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		list = new int[k];
		for(int i = 0; i < k; i++) {
			list[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(list);
		long start = 1;
		long end = list[k-1];		
		while(start <= end) {
			long count = 0;
			long mid = (start + end) / 2;
			for(int i = 0; i < k; i++) {
				count += list[i] / mid;
			}
			if(count < n) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		System.out.println(end);
	}
}
