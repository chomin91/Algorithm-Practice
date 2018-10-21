#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(int N) {
	int X_now, X_next;
	int M = 1000; // Maximum count
	unsigned int i, j;
	vector<int> table(1000000, 0);
	vector<vector<int>> tree(M);

	tree[0].push_back(N);

	if (N == 1) return 0;

	for (i = 0; i < M; i++) {
		for (j = 0; j < tree[i].size(); j++) {
			X_now = tree[i][j];
			if (X_now % 3 == 0) {
				X_next = X_now / 3;
				if (X_next == 1) return i + 1;
				else if (table[X_next] == 0) {
					tree[i + 1].push_back(X_next);
					table[X_next] = 1;
				}
			}
			if (X_now % 2 == 0) {
				X_next = X_now / 2;
				if (X_next == 1) return i + 1;
				else if (table[X_next] == 0) {
					tree[i + 1].push_back(X_next);
					table[X_next] = 1;
				}
			}
			X_next = X_now - 1;
			if (X_next == 1) return i + 1;
			else if (table[X_next] == 0) {
				tree[i + 1].push_back(X_next);
				table[X_next] = 1;
			}
		}
	}

}

int search_dp(int N) {
	int i;
	int* dp;
	dp = (int*)malloc(sizeof(int)*(N+1));

	dp[1] = 0;
	for (i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	return dp[N];
}

int main(void) {
	int N;
	int result_1, result_2;

	scanf("%d", &N);

	//result_1 = search(N);
	result_2 = search_dp(N);
	//printf("%d", result_1);
	printf("%d\n", result_2);

	return 0;
}