// BOJ 1764번: 듣보잡
import java.io.*;
import java.util.*;
public class practice02 {
	public static HashSet<String> hs = new HashSet<>();
	public static ArrayList<String> answer = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		for(int i = 0; i < N; i++) {
			hs.add(br.readLine());
		}
		for(int i = 0; i < M; i++) {
			String s = br.readLine();
			if(hs.contains(s)) {
				answer.add(s);
			}
		}
		Collections.sort(answer);
		System.out.println(answer.size());
		for(int i = 0; i < answer.size(); i++)
			System.out.println(answer.get(i));
	}
}
