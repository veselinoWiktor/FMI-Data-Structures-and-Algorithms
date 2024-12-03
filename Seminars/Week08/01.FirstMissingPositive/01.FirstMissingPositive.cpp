#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> us;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) us.insert(nums[i]);
    }

    for (int i = 1; i <= nums.size() + 1; i++) {
        if (us.count(i) == 0) {
            return i;
        }
    }
    return nums.size();
}

int main()
{
    std::cout << "Hello World!\n";
}
