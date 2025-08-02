#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <inttypes.h>
#include <stdint.h>

void Solve() {
  uint64_t n, m;
  std::cin >> n;
  std::cin >> m;

  uint64_t counter = n, i = 1, c = n;

  for(; i <= n && counter < m; i++) counter += --c;

  if (counter < m || m < n) {
    std::cout << "-1" << std::endl;
    return;
  }

  std::stringstream ss;

  ss << i << std::endl;

  if (i > 1) ss << i << " " << i-1 << std::endl;

  for(uint64_t j = 1; j <= i + (counter - m); j++)
    if (j != i && j != i-1) ss << i-1 << " " << j << std::endl;

  for(uint64_t j = i + (counter - m) + 1; j <= n; j++)
    if (j != i && j != i-1) ss << i << " " << j << std::endl;

  std::cout << ss.str();
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while(n--) Solve();

  return 0;
}
