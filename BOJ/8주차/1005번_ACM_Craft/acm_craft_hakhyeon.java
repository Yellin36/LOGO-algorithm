// BOJ 1005번: ACM Craft
import java.util.*;
import java.io.*;
public class practice05 {
    static int T; static int N; static int K; static int W;
    static int[] cost;
    static int[] in;
    static int[] result;
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
        	st = new StringTokenizer(br.readLine()," ");
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            
            cost = new int[N+1];
            in = new int[N+1];
            result = new int[N+1];
            
            st = new StringTokenizer(br.readLine());
            for(int i = 1; i <= N; i++) {
                cost[i] = Integer.parseInt(st.nextToken());
            }
            ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
            for(int i = 0; i <= N; i++) {
                list.add(i, new ArrayList<Integer>());
            }
            for(int i = 0; i < K; i++) {
            	st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                list.get(from).add(to);
                in[to]++;
            }
            W = Integer.parseInt(br.readLine());
            Queue<Integer> queue = new LinkedList<>();
            for(int i = 1; i < N+1; i++) {
                if(in[i] == 0) {
                    queue.add(i);
                    result[i] = cost[i];
                }
            }
            while (!queue.isEmpty()) { 
                int from = queue.poll();
                for(Integer to : list.get(from)) {
                    result[to] = Math.max(result[to], result[from] + cost[to]);
                    in[to]--;
                    if(in[to] == 0)
                        queue.add(to);
                }
            }
            System.out.println(result[W]);
        }
    }
}