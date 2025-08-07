#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX(x, y) ((x > y) ? x : y)

struct Pair {
  int l;
  int real;
  int r;
};

bool compare(const Pair& a, const Pair& b) {
  return a.l < b.l;
}

void Solve() {
  int n, x;

  scanf("%d %d", &n, &x);
  struct Pair a[n];

  for(int i = 0; i < n; i++) {
    scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].real);
  }

  std::sort(a, a+n, compare);

  for (int i = 0; i < n; i++) {
    if (a[i].l > x)
      break;

    x = MAX(x, a[i].real);
  }

  printf("%d\n", x);
}

int main(void) {
  int n;
  scanf("%d", &n);

  while(n--) Solve();

  return 0;
}
