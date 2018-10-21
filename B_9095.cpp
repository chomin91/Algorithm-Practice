#include <iostream>
using namespace std;

unsigned result[11];
unsigned answer[100];

int main(void) {
	int N, T, n, t;

	result[0] = 1;
	result[1] = 1;
	result[2] = 2;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &N);
		for (n = 3; n <= N; n++) {
			result[n] = result[n - 1] + result[n - 2] + result[n - 3];
		}
		answer[t] = result[N];
	}
	
	for (t = 0; t < T; t++) {
		printf("%u\n", answer[t]);
	}
	
	return 0;
}