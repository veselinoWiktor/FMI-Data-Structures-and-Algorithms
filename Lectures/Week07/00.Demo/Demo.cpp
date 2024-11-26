#include <iostream>

// Fibunacci example

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int dp[1000];

int fibDP(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = fibDP(n - 1) + fibDP(n - 2);
}


int main()
{
    int n;
    std::cin >> n;

    //std::cout << fib(n) << std::endl;
    std::cout << fibDP(n) << std::endl;
}

