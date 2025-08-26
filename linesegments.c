#include <stdio.h>
#include <math.h>

void Solve() {
  int n;
  float px, py, qx, qy;

  scanf("%d", &n);
  scanf("%f %f %f %f", &px, &py, &qx, &qy);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  int max = a[0], min = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      min = a[i] - max;
    } else if (a[i] < min) {
      min -= a[i];
    } else {
      min = 0;
    }

    max += a[i];
  }

  float distance =
    sqrt((qx-px) * (qx-px) + (qy-py) * (qy-py));

  if (min <= distance && max >= distance) {
    puts("YES");
  } else {
    puts("NO");
  }
}

int main() {
  int n;
  scanf("%d", &n);

  while(n--) Solve();
  return 0;
}
