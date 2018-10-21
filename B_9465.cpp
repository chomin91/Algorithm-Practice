#include <iostream>
#include <algorithm>
using namespace std;

int score[2][100000];
int sticker[2][100000];
int result[100000];

int main(void) {
	int t, T;
	int N, n, n1, n2;
	

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &N);
		for (n1 = 0; n1 < N; n1++) {
			scanf("%d", &sticker[0][n1]);
		}
		for (n2 = 0; n2 < N; n2++) {
			scanf("%d", &sticker[1][n2]);
		}

		score[0][0] = sticker[0][0];
		score[1][0] = sticker[1][0];
		score[0][1] = sticker[0][1] + sticker[1][0];
		score[1][1] = sticker[1][1] + sticker[0][0];

		for (n = 2; n < N; n++) {
			score[0][n] = max(score[1][n - 1], score[1][n - 2]) + sticker[0][n];
			score[1][n] = max(score[0][n - 1], score[0][n - 2]) + sticker[1][n];
		}

		result[t] = max(score[0][N - 1], score[1][N - 1]);
	}

	for (t = 0; t < T; t++) {
		printf("%d\n", result[t]);
	}

	return 0;
}