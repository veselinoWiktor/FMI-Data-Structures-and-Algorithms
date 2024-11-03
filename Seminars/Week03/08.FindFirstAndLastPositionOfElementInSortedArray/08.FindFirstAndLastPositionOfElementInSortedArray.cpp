#include <iostream>
#include <vector>


std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> res(2, -1);

    std::vector<int>::iterator first = std::lower_bound(nums.begin(), nums.end(), target);
    std::vector<int>::iterator second = std::upper_bound(nums.begin(), nums.end(), target);

    if (first == second) {
        return res;
    }

    res[0] = first - nums.begin();
    res[1] = second - nums.begin() - 1;
    return res;
}

int main()
{
    std::cout << "Hello World!\n";
}
