function solution(n, lost, reserve) {
  let answer = 0;

  let students = new Array(n).fill(1); //n개의수만큼1로차있는배열생성

  students.map((student, index) => {
    //map 을이용해서 students 각 요소들을 돌면서 잃어버리고, 여분가져온 체육복 갯수를 적용한 students 배열로 다시 return
    if (lost[index]) students[lost[index] - 1]--;
    if (reserve[index]) students[reserve[index] - 1]++;
  });

  for (let i = 0; i < n; i++) {
    //여분의체육복일 경우 앞,뒷 번호 학생에게 체육복을 빌려줌
    if (students[i] > 1) {
      if (students[i - 1] < 1) {
        students[i - 1]++;
        students[i]--;
      } else if (students[i + 1] < 1) {
        students[i + 1]++;
        students[i]--;
      }
    }
  }
  //배열의각요소가 0보다 경우(체육복을 입을 수있는 경우)의 legnth 를 answer에 리턴.
  answer = students.filter((student) => student > 0).length;

  return answer;
}
