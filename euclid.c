#include <stdio.h>
#include <stdbool.h>

int gcd(int u, int v) {
	int t;
	
	while (u > 0) {
		if (u < v) {t = u; u = v; v = t; }
		
		u = u-v;
	}
	
	return v;
}

int main(void) {
	int x, y;
	
	while(true) {
		scanf("%d %d", &x, &y);
		
		if (x > 0 && y > 0)
			printf("%d\n", gcd(x, y));
	}
}