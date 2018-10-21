#include <iostream>
using namespace std;

unsigned int tile[31];

int main(void) {
	int N, n ,i;

	scanf("%d", &N);
	
	tile[0] = 1;
	tile[2] = 3;

	for (n = 4; n <= N; n = n + 2) {
		tile[n] = tile[n - 2] * tile[2];
		for (i = 4; i <= n; i = i + 2) {
			tile[n] = tile[n] + tile[n - i] * 2;
		}
	}
	printf("%d\n", tile[N]);

	return 0;
}