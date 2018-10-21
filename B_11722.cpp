#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int length[1000];

int main(void) {
	int N, n, i;
	int max_length;

	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &A[n]);
	}

	length[0] = 1;
	max_length = 1;

	for (n = 1; n < N; n++) {
		length[n] = 1;
		for (i = n - 1; i >= 0; i--) {
			if (A[i] > A[n]) {
				length[n] = max(length[n], length[i] + 1);
			}
		}
		max_length = max(max_length, length[n]);
	}
	printf("%d\n", max_length);

	return 0;
}