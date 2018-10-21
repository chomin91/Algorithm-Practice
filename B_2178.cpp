#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int isVisit[101][101];
int cnt[101][101];

void escape() {
	int n, m;
	queue<int> q;

	q.push(1);
	q.push(1);
	isVisit[1][1] = 1;
	cnt[1][1] = 1;

	while (!q.empty()) {
		n = q.front();
		q.pop();
		m = q.front();
		q.pop();

		if ((n - 1 > 0) && (maze[n - 1][m] == 1) && (!isVisit[n - 1][m])) {
			q.push(n - 1);
			q.push(m);
			isVisit[n - 1][m] = 1;
			cnt[n - 1][m] = cnt[n][m] + 1;
		}

		if ((n + 1 <= 100) && (maze[n + 1][m] == 1) && (!isVisit[n + 1][m])) {
			q.push(n + 1);
			q.push(m);
			isVisit[n + 1][m] = 1;
			cnt[n + 1][m] = cnt[n][m] + 1;
		}

		if ((m - 1 > 0) && (maze[n][m - 1] == 1) && (!isVisit[n][m - 1])) {
			q.push(n);
			q.push(m - 1);
			isVisit[n][m - 1] = 1;
			cnt[n][m - 1] = cnt[n][m] + 1;
		}

		if ((m + 1 <= 100) && (maze[n][m + 1] == 1) && (!isVisit[n][m + 1])) {
			q.push(n);
			q.push(m + 1);
			isVisit[n][m + 1] = 1;
			cnt[n][m + 1] = cnt[n][m] + 1;
		}
	}
}

int main(void) {
	int n, m;
	char input[101];

	scanf("%d %d", &N, &M);

	for (n = 1; n <= N; n++) {
		scanf("%s", input);
		for (m = 1; m <= M; m++) {
			if (input[m-1] == '1') maze[n][m] = 1;
		}
	}

	escape();
	printf("%d\n", cnt[N][M]);
	
	return 0;
}