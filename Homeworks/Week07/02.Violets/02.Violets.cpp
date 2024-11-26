#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> result(n + 1, 0);
    result[1] = 2;
    result[2] = 2;

    for (int i = 3; i <= n; i++) {
        result[i] = (result[i - 1] + result[i - 2]) % 1000000007;
    }

    std::cout << result[n];

    return 0;
}
