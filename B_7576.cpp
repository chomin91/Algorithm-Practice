#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
int box[1000][1000];
int cnt[1000][1000];
int cnt_max;

void daycount(void) {
	int i, j;
	queue<int> q;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (box[i][j] == 1) {
				q.push(i);
				q.push(j);
			}
		}
	}

	while(!q.empty()){
		int m = q.front();
		q.pop();
		int n = q.front();
		q.pop();
		
		if ((m - 1 >= 0) && (box[m - 1][n] == 0)) {
			q.push(m - 1);
			q.push(n);

			box[m - 1][n] = 1;
			cnt[m - 1][n] = cnt[m][n] + 1;
			
			cnt_max = max(cnt_max, cnt[m - 1][n]);
		}

		if ((m + 1 < M) && (box[m + 1][n] == 0)) {
			q.push(m + 1);
			q.push(n);

			box[m + 1][n] = 1;
			cnt[m + 1][n] = cnt[m][n] + 1;
			
			cnt_max = max(cnt_max, cnt[m + 1][n]);
		}

		if ((n - 1 >= 0) && (box[m][n - 1] == 0)) {
			q.push(m);
			q.push(n - 1);

			box[m][n - 1] = 1;
			cnt[m][n - 1] = cnt[m][n] + 1;
			
			cnt_max = max(cnt_max, cnt[m][n - 1]);
		}

		if ((n + 1 < N) && (box[m][n + 1] == 0)) {
			q.push(m);
			q.push(n + 1);
			
			box[m][n + 1] = 1;
			cnt[m][n + 1] = cnt[m][n] + 1;
			
			cnt_max = max(cnt_max, cnt[m][n + 1]);
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (box[i][j] == 0) {
				cnt_max = -1;
			}
		}
	}
}

int main(void) {
	int i, j;
	cin >> N >> M;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cin >> box[i][j];
		}
	}

	daycount();
	cout << cnt_max << endl;

	return 0;
}