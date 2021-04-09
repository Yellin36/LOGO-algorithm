function findRouter(answer, start, tickets, airports) {
  if (tickets.length === 0) {
    answer.push([...airports, start]);
    return;
  }
  const destinations = tickets.filter((ticket) => ticket[0] === start);

  destinations.forEach((destination) => {
    const newTickets = tickets.filter((ticket) => ticket !== destination);
    findRouter(answer, destination[1], newTickets, [...airports, start]);
  });
}
function solution(tickets) {
  let answer = [];

  findRouter(answer, 'ICN', tickets, []);
  return answer.sort()[0];
}
