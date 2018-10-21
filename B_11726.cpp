#include <iostream>
using namespace std;

int main(void) {
	int i;
	int N;
	unsigned int* result;

	scanf("%d", &N);
	result = (unsigned int*)malloc(sizeof(unsigned int)*(N + 2));

	result[1] = 1;
	result[2] = 2;

	for (i = 3; i <= N; i++) {
		result[i] = (result[i-1] + result[i-2]) % 10007;
	}
	printf("%u\n", result[N]);
	return 0;
}