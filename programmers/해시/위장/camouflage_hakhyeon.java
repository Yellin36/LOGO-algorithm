// 프로그래머스 고득점 kit 해시 - 위장
import java.util.*;
import java.util.Map.Entry;
public class practice02 {
	public static int solution(String[][] clothes) {
		var map = new HashMap<String, Integer>();
		for(int i = 0; i < clothes.length; i++) {
			String key = clothes[i][1];
			map.put(key, map.getOrDefault(key, 0) + 1);
		}
		int answer = 1;
		for(Entry<String, Integer> entry : map.entrySet()) {
			answer *= entry.getValue() + 1;
		}
		return answer - 1;
	}
	
	public static void main(String[] args) {
		String[][] clothes = { {"yellow_hat", "headgear"},
								{"bule_sunglasses", "eyewear"},
								{"green_turban", "headgear"} };
		int answer = solution(clothes);
		System.out.println(answer);
	}
}
