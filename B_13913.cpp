#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int isVisit[100001];
int cnt[100001];
int path[100001];

void find_sister(void) {
	int i;
	int now_pos, next_pos;
	queue<int> q;
	q.push(N);
	isVisit[N] = 1;
	path[N] = N;

	while (!q.empty()) {
		now_pos = q.front();
		q.pop();
		if (now_pos == K) break;

		int moving[3] = { now_pos - 1, now_pos + 1, now_pos * 2 };
		for (i = 0; i < 3; i++) {
			next_pos = moving[i];

			if (next_pos >= 0 && next_pos <= 100000 && !isVisit[next_pos]) {
				q.push(next_pos);
				isVisit[next_pos] = 1;
				cnt[next_pos] = cnt[now_pos] + 1;
				path[next_pos] = now_pos;
			}
		}
	}
}

int main(void) {
	int i;
	int path_n;
	vector<int> path_result;

	scanf("%d %d", &N, &K);

	find_sister();

	printf("%d\n", cnt[K]);
	
	path_n = K;

	for (i = 0; i <= cnt[K]; i++) {
		path_result.push_back(path_n);
		path_n = path[path_n];
	}
	
	for (i = 0; i <= cnt[K]; i++) {
		printf("%d ", path_result.back());
		path_result.pop_back();
	}
	printf("\n");
	return 0;
}