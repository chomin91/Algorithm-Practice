#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int length[1000];
int rev_length[1000];
int biotonic_length[1000];

int main(void) {
	int N, n, i;
	int max_length = 0;

	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &A[n]);
	}
	
	length[0] = 1;
	for (n = 1; n < N; n++) {
		length[n] = 1;

		for (i = n - 1; i >= 0; i--) {
			if (A[i] < A[n]) {
				length[n] = max(length[n], length[i] + 1);
			}
		}
	}

	rev_length[N - 1] = 1;
	for (n = N - 2; n >= 0; n--) {
		rev_length[n] = 1;

		for (i = n + 1; i < N; i++) {
			if (A[i] < A[n]) {
				rev_length[n] = max(rev_length[n], rev_length[i] + 1);
			}
		}
	}

	for (n = 0; n < N; n++) {
		biotonic_length[n] = length[n] + rev_length[n] - 1;
		max_length = max(max_length, biotonic_length[n]);
	}

	printf("%d\n", max_length);

	return 0;
}