#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = left + (right - left) / 2;

    while (left <= right) {
        if (nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

        mid = left + (right - left) / 2;
    }

    return mid - 1;
}

int main()
{
    std::cout << "Hello World!\n";
}