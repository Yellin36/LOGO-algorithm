// 프로그래머스 고득점 kit 해시 - 완주하지 못한 선수
import java.util.*;
public class practice11 {
	/* 풀이 1 - HashMap과 getOrDefault를 활용하는 방법
	public String solution(String[] participant, String[] completion) {
        Map<String, Integer> hm = new HashMap<>();
        for(String a : participant) hm.put(a, hm.getOrDefault(a, 0)+1);
        for(String a : completion) hm.put(a, hm.getOrDefault(a, 0)-1);
        for(String a : hm.keySet()){
            if(hm.get(a) != 0) return a;
        }

        return null;
    }
    */
	
	// 풀이 2 - 단순 정렬하여 풀기
	public String solution(String[] participant, String[] completion) {
		Arrays.sort(participant);
		Arrays.sort(completion);
		for(int i = 0; i < completion.length; i++) {
			if(!participant[i].equals(completion[i]))
				return participant[i];
		}
		return participant[participant.length - 1];
	}
}
