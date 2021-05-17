// BOJ 9375번: 패션왕 신해빈
import java.io.*;
import java.util.*;
import java.util.Map.Entry;
public class practice03 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		while(TC-- > 0) {
			int n = Integer.parseInt(br.readLine());
			String[][] clothes = new String[n][2];
			for(int i = 0; i < clothes.length; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine()," ");
				clothes[i][0] = st.nextToken();
				clothes[i][1] = st.nextToken();
			}
			var map = new HashMap<String, Integer>();
			for(int i = 0; i < clothes.length; i++) {
				String key = clothes[i][1];
				map.put(key, map.getOrDefault(key, 0) + 1);
			}
			int answer = 1;
			for(Entry<String, Integer> entry : map.entrySet()) {
				answer *= entry.getValue() + 1;
			}
			System.out.println(answer - 1);
		}
	}
}