#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int series_sum[1000];

int main(void) {
	int N, n, i;
	int max_sum;

	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &A[n]);
	}

	series_sum[0] = A[0];
	max_sum = A[0];

	for (n = 1; n < N; n++) {
		series_sum[n] = A[n];
		for (i = n - 1; i >= 0; i--) {
			if (A[i] < A[n]) {
				series_sum[n] = max(series_sum[n], series_sum[i] + A[n]);
			}
		}
		max_sum = max(max_sum, series_sum[n]);
	}

	printf("%d\n", max_sum);

	return 0;
}