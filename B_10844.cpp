#include <iostream>
int N;
long long cnt[10][101];

int main(void) {
	int i, n, num ;
	long long result = 0;

	scanf("%d", &N);

	for (i = 0; i <= 9; i++) {
		cnt[i][1] = 1;
	}

	for (n = 2; n <= N; n++) {
		cnt[0][n] = cnt[1][n - 1] % 1000000000;
		cnt[9][n] = cnt[8][n - 1] % 1000000000;
		for (num = 1; num <= 8; num++) {
			cnt[num][n] = (cnt[num - 1][n - 1] + cnt[num + 1][n - 1]) % 1000000000 ;
		}
	}

	for (i = 1; i <= 9; i++) {
		result += cnt[i][N];
	}
	
	printf("%lld\n", result % 1000000000);
	return 0;
}