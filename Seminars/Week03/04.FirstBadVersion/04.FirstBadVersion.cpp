#include <iostream>

bool isBadVersion(int version) {
    // given in leetcode problem
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int mid = left + (right - left) / 2;

    while (left <= right) {
        if (!isBadVersion(mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

        mid = left + (right - left) / 2;
    }

    return mid;
}

int main()
{
    std::cout << "Hello World!\n";
}