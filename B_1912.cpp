#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int A_sum[100000];
int main(void) {
	int N, n;
	int max_sum = 0;

	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &A[n]);
	}

	A_sum[0] = A[0];
	max_sum = A[0];

	for (n = 1; n < N; n++) {
		A_sum[n] = A[n];

		if (A_sum[n - 1] > 0) {
			A_sum[n] = A[n] + A_sum[n - 1];
		}
		max_sum = max(max_sum, A_sum[n]);
	}

	printf("%d\n", max_sum);
	return 0;
}