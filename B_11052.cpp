#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int prize[1001];
int result[1001];

int main(void) {
	int N, n;
	int i, j;

	scanf("%d", &N);

	for (n = 1; n <= N; n++) {
		scanf("%d", &prize[n]);
	}
	result[1] = prize[1];

	for (i = 2; i <= N; i++) {
		result[i] = prize[i];
		for (j = i - 1; j >= ceil(i / 2); j--) {
			result[i] = max(result[i], result[j] + result[i - j]);
		}
	}

	printf("%d\n", result[N]);
	return 0;
}