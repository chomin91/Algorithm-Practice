#include <iostream>
using namespace std;

int main(void) {
	int T, t, N, n;
	long long int *result;
	long long int P[101];
	int i;

	scanf("%d", &T);
	result = (long long*)malloc(sizeof(long long)*T);

	for (t = 0; t < T; t++) {
		i = 1;
		P[1] = 1;
		P[2] = 1;
		P[3] = 1;
		P[4] = 2;
		P[5] = 2;

		scanf("%d", &N);

		for (n = 6; n <= N; n++) {
			P[n] = P[n - 1] + P[i];
			i++;
		}
		result[t] = P[N];
	}

	for (t = 0; t < T; t++) {
		printf("%lld\n", result[t]);
	}

	return 0;
}