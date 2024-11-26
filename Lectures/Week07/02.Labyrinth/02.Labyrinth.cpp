#include <iostream>

const int INF = INT_MAX - 1;

int dp[1000][1000];
int a[1000][1000];
int n, m;

int ans(int x, int y) {
	if (dp[x][y] != 0) {
		return dp[x][y];
	}

	if (x == 0) {
		return dp[x][y] = ans(x, y - 1) + a[x][y];
	}
	if (y == 0) {
		return dp[x][y] = ans(x - 1, y) + a[x][y];
	}

	return dp[x][y] = std::min(ans(x - 1, y), ans(x, y - 1)) + a[x][y];
}

int ansLinear() {
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + a[i][0];
	}

	for (int j = 1; j < m; j++) {
		dp[0][j] = dp[0][j - 1] + a[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}

	return dp[n - 1][m - 1];
}

int main()
{
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}

	dp[0][0] = a[0][0];
	//std::cout << ans(n - 1, m - 1) << std::endl;
	std::cout << ansLinear() << std::endl;
}