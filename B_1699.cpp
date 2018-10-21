#include <iostream>
using namespace std;

int square_cnt[100001];

int main(void) {
	int N, i, j;
	int now_num, next_num;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j*j <= i; j++) {
			if (square_cnt[i] > square_cnt[i-j*j] + 1|| square_cnt[i] == 0)
				square_cnt[i] = square_cnt[i - j*j] + 1;
		}
	}

	/*
	for (i = 1; i*i <= N; i++) {
		q.push(i*i);
		square_cnt[i*i] = 1;
	}

	while (!q.empty()) {
		now_num = q.front();
		q.pop();

		for (j = 1; now_num + j*j <= N; j++) {
			next_num = now_num + j*j;
			if (square_cnt[next_num] == 0) {
				square_cnt[next_num] = square_cnt[now_num] + 1;
				q.push(next_num);
			}
		}
	}
	*/
	printf("%d\n", square_cnt[N]);

	return 0;
}