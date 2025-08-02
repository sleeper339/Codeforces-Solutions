#include <queue>
#include <vector>
#include <iostream>
#include <cstdlib>

#define LMAO(a) ((a ^ (a+1)) & (a+1))

using ulong = unsigned long;

struct Compare {
  bool operator()(const ulong& a, const ulong& b) {
    return (a ^ (a+1)) > (b ^ (b+1));
  }
};

using PriorityQueue = std::priority_queue<ulong, std::vector<ulong>, Compare>;

void Solve() {
  PriorityQueue a;
  int n;
  unsigned long k;

  std::cin >> n >> k;

  for(int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    a.push(input);
  }

  while(true) {
    ulong c = a.top();
    ulong minCost = LMAO(c);
    if(minCost > k)
      break;

    c += minCost;
    k -= minCost;
    a.pop();
    a.push(c);
  }

  int sum = 0;
  while(!a.empty()) {
    for(ulong c = a.top(); c > 0; sum += (c & 1), c /= 2);
    a.pop();
  }

  std::cout << sum << std::endl; //Hello
}

int main(void) {
  int n;
  std::cin >> n;

  while(n--) Solve();

  return 0;
}
