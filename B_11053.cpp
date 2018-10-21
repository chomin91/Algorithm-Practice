#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int length[1001];

int main(void) {
	int N, n;
	int i;
	int max_length = 1;

	scanf("%d", &N);
	for (n = 1; n <= N; n++) {
		scanf("%d", &A[n]);
	}
	
	length[1] = 1;
	for (n = 2; n <= N; n++) {
		length[n] = 1;
		for (i = n - 1; i >= 1; i--) {
			if (A[i] < A[n]) {
				length[n] = max(length[n], length[i] + 1);
			}
		}
		max_length = max(max_length, length[n]);
	}

	printf("%d\n", max_length);

	return 0;
}