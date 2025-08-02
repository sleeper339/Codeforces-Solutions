#include <stdio.h>

int s[100005];
const int mod = 998244353;

void Solve() {
	int n;
	scanf("%d", &n);
	
	int a[n];
	int b[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	
	int maxa = a[0], maxai = 0;
	int maxb = b[0], maxbi = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] > maxa) {
			maxa = a[i];
			maxai = i;
		}
		
		if(b[i] > maxb) {
			maxb = b[i];
			maxbi = i;
		}
		
		if (maxa > maxb) {
			printf("%d ", (s[maxa] + s[b[i - maxai]]) % mod);
		} else if(maxb > maxa) {
			printf("%d ", (s[maxb] + s[a[i - maxbi]]) % mod);
		} else {
			const int max = b[i - maxai] > a[i - maxbi] ? b[i - maxai] : a[i - maxbi];
			printf("%d ", (s[maxa] + s[max]) % mod);
		}
	}
	
	printf("\n");
}

int main() {
	s[0] = 1;
	for(int i = 1; i < 100005; i++) s[i] = s[i-1] * 2 % mod;
	int n;
	scanf("%d", &n);
	
	while(n--) Solve();
	
	return 0;
}