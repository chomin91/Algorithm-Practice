#include <iostream>
#include <algorithm>

using namespace std;

int wine[10000];
int max_wine[10000];

int main(void) {
	int n, N;
	scanf("%d", &N);

	for (n = 0; n < N; n++) {
		scanf("%d", &wine[n]);
	}
	max_wine[0] = wine[0];
	max_wine[1] = wine[0] + wine[1];
	max_wine[2] = max(max_wine[1], max(wine[2] + wine[1], wine[2] + wine[0]));

	for (n = 3; n < N; n++) {
		max_wine[n] = max(max_wine[n - 1], max(max_wine[n - 2] + wine[n], max_wine[n - 3] + wine[n - 1] + wine[n]));
	}

	printf("%d\n", max_wine[N-1]);

	return 0;
}