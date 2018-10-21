#include <iostream>
using namespace std;

int cnt[10][1001];

int main(void) {
	int i, N, n;
	int num, num_g;
	int result = 0;

	scanf("%d", &N);
	
	for (i = 0; i <= 9; i++) {
		cnt[i][1] = 1;
	}

	for (n = 2; n <= N; n++) {
		for (num = 0; num <= 9; num++) {
			for (num_g = num; num_g <= 9; num_g++) {
				cnt[num][n] += cnt[num_g][n - 1] % 10007;
			}
		}
	}

	for (i = 0; i <= 9; i++) {
		result += cnt[i][N];
	}

	printf("%d\n", result % 10007);
	return 0;
}