#include <iostream>
using namespace std;

unsigned long long cnt[2][91];

int main(void) {
	int N, n;
	
	scanf("%d", &N);
	
	cnt[0][1] = 1;
	cnt[1][1] = 1;

	for (n = 2; n <= N; n++) {
		cnt[0][n] = cnt[1][n - 1] + cnt[0][n - 1];
		cnt[1][n] = cnt[0][n - 1];
	}

	printf("%llu\n", cnt[1][N]);

	return 0;
}