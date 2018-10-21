#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int tree[100001];
int depth[100001];
int ancestor_1;
int ancestor_2;
int result[100000];

int find_ancestor(int node_1, int node_2) {
	int depth_diff;
	int depth_equal;
	int i;
	int depth_init;
	
	ancestor_1 = tree[node_1];
	ancestor_2 = tree[node_2];

	if (depth[node_1] > depth[node_2]) {
		depth_init = depth[node_2];
		depth_diff = depth[node_1] - depth[node_2];
		for (i = 0; i < depth_diff; i++) {
			if (ancestor_1 == node_2) return node_2;
			else ancestor_1 = tree[ancestor_1];
		}
	}

	else if (depth[node_1] < depth[node_2]) {
		depth_init = depth[node_1];
		depth_diff = depth[node_2] - depth[node_1];
		for (i = 0; i < depth_diff; i++) {
			if (ancestor_2 == node_1) return node_1;
			else ancestor_2 = tree[ancestor_2];
		}
	}
	else depth_init = depth[node_1];

	for (i = 1; i < depth_init; i++){
		if (ancestor_1 == ancestor_2) break;
		ancestor_1 = tree[ancestor_1];
		ancestor_2 = tree[ancestor_2];
	}
	return ancestor_1;
}

int main(void) {
	int n1, n2;
	int fn1, fn2;
	int i;

	scanf("%d", &N);

	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &n1, &n2);
		if (n1 > n2) {
			tree[n1] = n2;
			depth[n1] = depth[n2] + 1;
		}
		else {
			tree[n2] = n1;
			depth[n2] = depth[n1] + 1;
		}
	}
	
	scanf("%d", &M);
	for (i = 0; i < M; i++) {;
		scanf("%d %d", &fn1, &fn2);
		result[i] = find_ancestor(fn1, fn2);
	}

	for (i = 0; i < M; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}