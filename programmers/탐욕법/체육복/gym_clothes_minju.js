function solution(n, lost, reserve) {
  //순간순가 최적의 해를 찾는다.
  //여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
  //여벌 체육복을 가져온 학생이 체육복을 도난 당했을 수도 있다.
  let answer = 0;

  let students = new Array(n).fill(1);

  students.map((student, index) => {
    if (lost[index]) students[lost[index] - 1]--;
    if (reserve[index]) students[reserve[index] - 1]++;
  });
  console.log(students);
  for (let i = 0; i < n; i++) {
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

  answer = students.filter((student) => student > 0).length;

  return answer;
}
