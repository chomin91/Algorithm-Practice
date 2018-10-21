#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, I;
int start_x, start_y, end_x, end_y;
int chessboard[300][300];
int isVisit[300][300];
int cnt[300][300];

int night(void) {
	int now_x, now_y;
	int next_x, next_y;
	int move_night[8][2] = { { -2, 1 },{ -1, 2 },{ 1, 2 },{ 2, 1 },{ -2, -1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };

	queue<int> q;
	q.push(start_y);
	q.push(start_x);

	while (!q.empty()) {
		now_y = q.front();
		q.pop();
		now_x = q.front();
		q.pop();

		if (now_x == end_x && now_y == end_y) {
			break;
		}

		for (int i = 0; i < 8; i++) {
			next_x = now_x + move_night[i][0];
			next_y = now_y + move_night[i][1];

			if (next_x >= 0 && next_y >= 0 && next_x < I && next_y < I) {
				if (!isVisit[next_y][next_x]) {
					q.push(next_y);
					q.push(next_x);
					isVisit[next_y][next_x] = 1;
					cnt[next_y][next_x] = cnt[now_y][now_x] + 1;
				}
			}
		}
	}

	return cnt[end_y][end_x];
}

int main(void) {
	int i, j, t;
	vector<int> result;

	scanf("%d", &T);
	
	for (t = 0; t < T; t++) {
		scanf("%d", &I);
		scanf("%d %d", &start_x, &start_y);
		scanf("%d %d", &end_x, &end_y);

		result.push_back(night());

		for (i = 0; i < I; i++) {
			for (j = 0; j < I; j++) {
				cnt[i][j] = 0;
				isVisit[i][j] = 0;
			}
		}
	}

	for (t = 0; t < T; t++) {
		printf("%d\n", result[t]);
	}
	
	return 0;
}