class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        for(int i=1; i<triangle.length; i++) {	// 왼쪽 + 오른쪽
            triangle[i][0] += triangle[i-1][0];
            triangle[i][triangle[i].length - 1] += triangle[i-1][triangle[i].length - 2];
        }
	for(int i=1; i<triangle.length; i++) {	// 가운데
	    for(int j=1; j<triangle[i].length-1; j++) {
	     	triangle[i][j] += (triangle[i-1][j-1] > triangle[i-1][j]) ? triangle[i-1][j-1] : triangle[i-1][j];           	
	    }
	}
	for(int i=0; i<triangle[triangle.length-1].length; i++) {	// 최대값 찾기
	    if(triangle[triangle.length-1][i] > answer) answer = triangle[triangle.length-1][i];
        }	        
        return answer;
    }
}
