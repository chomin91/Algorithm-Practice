#include <iostream>

using namespace std;

int num_1[10001];
int num_2[10001];

void pf(int a, int* result) {
	for (int i=2; i<=a; i++) {
		while (a%i == 0) {
			result[i]++;
			a /= i;
		}
	}
}

int main() {
	int n1, n2;
	int div = 1;
	int mul = 1;

	cin >> n1 >> n2;
	pf(n1, num_1);
	pf(n2, num_2);

	for (int i = 2; i < 10001; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			continue;
		
		if (num_1[i] >= num_2[i]) {
			for (int j = 0; j < num_1[i]; j++) {
				mul *= i;
			}
			for (int k = 0; k < num_2[i]; k++) {
				div *= i;
			}
		} else {
			for (int j = 0; j < num_1[i]; j++) {
				div *= i;
			}
			for (int k = 0; k < num_2[i]; k++) {
				mul *= i;
			}
		}
	}

	cout << div << endl;
	cout << mul << endl;
	
	return 0;
}
