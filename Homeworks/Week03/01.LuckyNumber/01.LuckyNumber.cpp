#include <iostream>
#include <vector>

long long calculateSweets(long long left, long long right, long long x, long long recursionLvl = 0) {
    if (left == right) {
        return recursionLvl + 1;
    }

    long long mid1 = left + (right - left) / 3;
    long long mid2 = right - (right - left) / 3;

    if (x <= mid1)
        return calculateSweets(left, mid1, x, recursionLvl + 1);
    else if (x >= mid2)
        return calculateSweets(mid2, right, x, recursionLvl + 1);
    else
        return recursionLvl + 1;
}

int main()
{
    int n = 0, p = 0;
    std::cin >> p >> n;

    long long all = powl(3, p);
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> curr;
        std::cout << calculateSweets(1, all, curr) << std::endl;
    }
}

