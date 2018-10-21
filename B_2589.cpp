#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int row, col;
int map[50][50];
int isVisit[50][50];
int cnt[50][50];
int cnt_max;

void find_treasure(void) {
	int i, j, r, c;
	int now_r, now_c, next_r, next_c;
	int moving[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	queue<int> q;

	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			if (map[r][c] == 1) {
				q.push(r);
				q.push(c);
				isVisit[r][c] = 1;

				while (!q.empty()) {
					now_r = q.front();
					q.pop();
					now_c = q.front();
					q.pop();

					for (i = 0; i < 4; i++) {
						next_r = now_r + moving[i][0];
						next_c = now_c + moving[i][1];

						if (next_r >= 0 && next_c >= 0 && next_r < row && next_c < col) {
							if (map[next_r][next_c] == 1 && !isVisit[next_r][next_c]) {
								q.push(next_r);
								q.push(next_c);
								isVisit[next_r][next_c] = 1;
								cnt[next_r][next_c] = cnt[now_r][now_c] + 1;
							}
						}
					}
				}
				for (i = 0; i < row; i++) {
					for (j = 0; j < col; j++) {
						cnt_max = max(cnt[i][j], cnt_max);
					}
				}
				for (i = 0; i < row; i++) {
					for (j = 0; j < col; j++) {
						isVisit[i][j] = 0;
						cnt[i][j] = 0;
					}
				}
			}
		}
	}
}

int main(void) {
	int i, j;
	char input[50];

	scanf("%d %d", &row, &col);
	for (i = 0; i < row; i++) {
		scanf("%s", &input);
		for (j = 0; j < col; j++) {
			if (input[j] == 'L') map[i][j] = 1;
		}
	}

	find_treasure();

	printf("%d\n", cnt_max);
	return 0;
}