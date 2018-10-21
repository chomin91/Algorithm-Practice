#include <iostream>
#include <algorithm>
using namespace std;

int stairs[300];
int score[300];

int main(void) {
	int N, n;

	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &stairs[n]);
	}

	score[0] = stairs[0];
	score[1] = stairs[0] + stairs[1];
	score[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (n = 3; n < N; n++) {
		score[n] = max(score[n - 2] + stairs[n], score[n - 3] + stairs[n - 1] + stairs[n]);
	}

	printf("%d\n", score[N - 1]);

	return 0;
}