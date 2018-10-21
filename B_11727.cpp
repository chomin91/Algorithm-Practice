#include <iostream>
using namespace std;

int main(void) {
	int N, n;
	unsigned int* result;

	scanf("%d", &N);
	result = (unsigned int*)malloc(sizeof(unsigned int)*(N+2));

	result[1] = 1;
	result[2] = 3;
	for (n = 3; n <= N; n++) {
		result[n] = ( result[n - 1] + 2 * result[n - 2] ) % 10007;
	}

	printf("%u\n", result[N]);
	return 0;
}