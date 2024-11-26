#include <iostream>
#include <climits>

const int INF = INT_MAX - 1;

int myMin(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}

int slowAns(int x) {
	if (x == 0) {
		return 0;
	}

	if (x < 0) {
		return INF;
	}

	int val = myMin(slowAns(x - 2), slowAns(x - 3), slowAns(x - 7));

	if (val == INF) {
		return INF;
	}

	return val + 1;
}

int dp[100000];

int fastAns(int x) {
	if (x == 0) {
		return 0;
	}

	if (x < 0) {
		return INF;
	}

	if (dp[x] != 0) {
		return dp[x];
	}

	int val = myMin(fastAns(x - 2), fastAns(x - 3), fastAns(x - 7));
	if (val == INF) {
		return INF;
	}

	return dp[x] = val + 1;
}

int linearAns01(int x) {
	dp[0] = 0;

	for (int i = 1; i <= x; i++) {
		dp[i] = INF;
	}

	int val1 = INF, val2 = INF, val3 = INF;

	for (int i = 1; i <= x; i++) {
		if (i >= 2) {
			val1 = dp[i - 2];
		}
		if (i >= 3) {
			val2 = dp[i - 3];
		}
		if (i >= 7) {
			val3 = dp[i - 7];
		}

		dp[i] = myMin(val1, val2, val3) + 1;
	}

	return dp[x];
}

int linearAns02(int x) {
	dp[0] = 0;

	for (int i = 1; i <= x; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i <= x; i++) {
		dp[i + 2] = std::min(dp[i] + 1, dp[i + 2]);
		dp[i + 3] = std::min(dp[i] + 1, dp[i + 3]);
		dp[i + 7] = std::min(dp[i] + 1, dp[i + 7]);
	}

	return dp[x];
}

int main() {
	int n = 0;
	std::cin >> n;
	std::cout << linearAns02(n) << std::endl;
}