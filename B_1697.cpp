#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int isVisit[100001];
int cnt[100001];

int search() {
	queue<int> q;

	q.push(N);
	isVisit[N] = 1;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == K) return cnt[K];
		
		if ((pos - 1 >= 0) && (!isVisit[pos - 1])) {
			q.push(pos - 1);
			isVisit[pos - 1] = 1;
			cnt[pos - 1] = cnt[pos] + 1;
		}

		if ((pos + 1 <= 100000) && (!isVisit[pos + 1])) {
			q.push(pos + 1);
			isVisit[pos + 1] = 1;
			cnt[pos + 1] = cnt[pos] + 1;
		}

		if ((pos * 2 <= 100000) && (!isVisit[pos * 2])) {
			q.push(pos * 2);
			isVisit[pos * 2] = 1;
			cnt[pos * 2] = cnt[pos] + 1;
		}

	}
}

int main(void) {
	int result;

	cin >> N >> K;
	result  = search();
	cout << result << endl;
	
	return 0;
}