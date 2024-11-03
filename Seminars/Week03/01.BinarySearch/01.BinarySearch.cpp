#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> nums{ -1, 0, 3, 5, 9, 12 };
    search(nums, 9);
    std::cout << "Hello World!\n";
}