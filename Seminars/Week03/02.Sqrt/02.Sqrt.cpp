#include <iostream>

int mySqrt(int x) {
    int left = 0;
    int right = x;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left - 1;
}

int main()
{
    std::cout << mySqrt(4);
}