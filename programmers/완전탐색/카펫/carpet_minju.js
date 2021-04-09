const solution = (brown, yellow) => {
  let answer = [];
  const total = brown + yellow;

  for (let h = 3; h <= total; h++) {
    const x = total / h;
    if (Number.isInteger(x) && x >= h && (x - 2) * (h - 2) === yellow) {
      answer.push(x);
      answer.push(h);
      break;
    }
  }

  return answer;
};
