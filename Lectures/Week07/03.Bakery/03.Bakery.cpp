#include <iostream>

int dp[1000][1000];
int a[1000]; // cena
int w[1000]; // hranitelna stoinost
int n; // number of banichki
int x; // ostanali pari

int ans(int _n, int _x) {
    if (dp[_n][_x] != 0) {
        return dp[_n][_x];
    }

    if (_n == 0) {
        return 0;
    }

    if (_x < w[_n - 1]) {
        return dp[_n][_x] = ans(_n - 1, _x);
    }

    return dp[_n][_x] = std::max(ans(_n - 1, _x), ans(_n - 1, _x - a[_n - 1]) + w[_n - 1]);
}

int ansLinear() {
    int min = a[0];
    for (int i = 1; i <= n; i++) {
        int curr = a[i - 1];

        if (curr < min) {
            min = curr;
        }
        else {
            for (int j = min; j < curr; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }

        for (int j = curr; j <= x; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + w[i - 1]);
        }
    }

    return dp[n][x];
}

int main()
{
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::cout << ans(n + 1, x) << std::endl;
    //std::cout << ansLinear() << std::endl;
}