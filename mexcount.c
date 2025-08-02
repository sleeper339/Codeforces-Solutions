#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (x < y ? x : y)

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

static inline int countLessOrEqual(int arr[], int n, int val) {
  int low = 0, high = n;

  while (low < high) {
    int mid = (high + low) / 2;
    if (arr[mid] <= val)
      low = mid + 1;
    else
      high = mid;
  }

  return low;
}

void Solve() {
  int n;
  scanf("%d", &n);

  int a[n], count[n+1];

  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), compare);

  int mex = 0, i = 0;
  count[0] = 0;
  while (i < n) {
    if (a[i] != mex) break;

    while (i < n && a[i] == mex){
      count[mex]++;
      i++;
    }
    mex++;
    count[mex] = 0;
  }

  qsort(count, mex+1, sizeof(int), compare);

  for(int k = 0; k <= n; k++) {
    int c = countLessOrEqual(count, mex+1, k);
    printf("%d ", MIN(c, n-k+1));
  }
  puts("");
}

int main(void) {
  int n;
  scanf("%d", &n);

  while(n--) Solve();

  return 0;
}
