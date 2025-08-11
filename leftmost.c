#include <stdio.h>

void Solve() {
	int n;
	scanf("%d", &n);
	
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int minLeft = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > 2 * minLeft - 1) {
			printf("NO\n");
			return;
		}
		
		if (a[i] < minLeft)
			minLeft = a[i];
	}
	
	printf("YES\n");
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	while(n--) Solve();
}