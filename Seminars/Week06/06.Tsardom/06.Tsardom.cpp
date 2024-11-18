#include <iostream>
#include <vector>

const int N = 1000001;

std::vector<int> tree[1000001];
long long sums[N]{ 0 };

void dfs(int v) {

	for (auto x : tree[v]) {
		dfs(x);
		sums[v] += sums[x] + 1;
	}
}

int main()
{
	int N;
	std::cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;
		tree[a].push_back(b);
	}

	dfs(0);

	for (int i = 0; i < N; i++) {
		std::cout << sums[i] << " ";
	}
}