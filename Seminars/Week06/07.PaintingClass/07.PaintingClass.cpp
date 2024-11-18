#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <deque>

const int N = 1000001;

std::vector<int> tree[N];
long long sums[N];
long long max = LLONG_MIN;

void initSums() {
	for (int i = 0; i < N; i++) {
		sums[i] = 1;
	}
}

void dfs(int v) {
	for (auto x : tree[v]) {
		dfs(x);
		sums[v] += sums[x];
	}
}

void findMax(int v) {
	long long curr = 1;

	if (v != 0) {
		curr = sums[0] - sums[v];
	}

	for (auto x : tree[v]) {
		curr *= sums[x];
	}
	if (curr > max) max = curr;

	for (auto x : tree[v])
	{
		findMax(x);
	}
}

int main()
{
	initSums();
	int N = 0;
	std::cin >> N;

	std::deque<int> q;
	q.push_front(0);

	int left, right;
	for (int i = 0; i < N; i++) {
		int curr = q.front();
		q.pop_front();

		std::cin >> left >> right;
		if (right != -1) {
			tree[curr].push_back(right);
			if (right < q.front())
				q.push_front(right);
			else
				q.push_back(right);
		}
		if (left != -1)
		{
			tree[curr].push_back(left);
			if (left < q.front())
				q.push_front(left);
			else
				q.push_front(left);
		}
	}

	dfs(0);

	findMax(0);

	std::cout << max;
}