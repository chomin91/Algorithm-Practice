#include <iostream>

using namespace std;

int result[500];
int bin[9];

int main() {
	int n, k;
	int total_cnt = 0;
	
	cin >> n >> k;
	
	for (int n = 0;; n++) {
		int temp = n;
		int cnt = 0;
		bin[cnt++] = temp % 2;
		temp = temp >> 1;
		
		while (temp != 0) {
			bin[cnt++] = temp % 2;
			temp = temp >> 1;
		}
		for (int m = 0; m < cnt; m++) {
			if (total_cnt + m < 500)
				result[total_cnt + m] = bin[cnt - m - 1];
		}
		total_cnt += cnt;
		if (total_cnt >= 500)
			break;
	}
	
	for (int i = 0; i < 5; i++) {
		cout << result[k + n*i - 1] << " ";
	}

	cout << endl;
	return 0;
}
