#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
int map[101][101];
int break_cnt[101][101];
int now_break_cnt[101][101];

void wall_breaker(void) {
	int i,j;
	int n_now, m_now, n_next, m_next;
	queue<int> q;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			break_cnt[i][j] = 100000;
		}
	}
	break_cnt[1][1] = 0;

	int moving[4][2] = { {0, -1},{0, 1},{1, 0},{-1, 0} };
	q.push(1);
	q.push(1);

	while (!q.empty()) {
		n_now = q.front();
		q.pop();
		m_now = q.front();
		q.pop();

		for (i = 0; i < 4; i++) {
			n_next = n_now + moving[i][1];
			m_next = m_now + moving[i][0];

			if (n_next >= 1 && m_next >= 1 && n_next <= N && m_next <= M) {
				if (map[n_next][m_next] == 1) {
					if (break_cnt[n_next][m_next] > now_break_cnt[n_now][m_now] + 1) {
						q.push(n_next);
						q.push(m_next);
						now_break_cnt[n_next][m_next] = now_break_cnt[n_now][m_now] + 1;
						break_cnt[n_next][m_next] = now_break_cnt[n_next][m_next];
					}
					
				}
				else if (map[n_next][m_next] == 0) {
					if (break_cnt[n_next][m_next] > now_break_cnt[n_now][m_now]) {
						q.push(n_next);
						q.push(m_next);
						now_break_cnt[n_next][m_next] = now_break_cnt[n_now][m_now];
						break_cnt[n_next][m_next] = now_break_cnt[n_next][m_next];
					}

				}
			}
		}
	}
}

int main(void) {
	int m, n;
	char input[101];

	scanf("%d %d", &M, &N);
	
	for (n = 1; n <= N; n++) {
		scanf("%s", input);
		for (m = 1; m <= M; m++) {
			if (input[m-1] == '1') {
				map[n][m] = 1;
			}
		}
	}

	wall_breaker();
	printf("%d\n", break_cnt[N][M]);
	return 0;
}