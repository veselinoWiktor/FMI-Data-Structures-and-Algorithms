// 07.Search2DMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
}

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int upRow = 0;
        int downRow = matrix.size() - 1;

        int resultRow = 0;
        while (upRow <= downRow) {
            int midRow = upRow + (downRow - upRow) / 2;
            if (matrix[midRow][0] > target) {
                downRow = midRow - 1;
            }
            else if (target <= matrix[midRow].back()) {
                resultRow = midRow;
                break;
            }
            else {
                upRow = midRow + 1;
            }
        }

        int left = 0;
        int right = matrix[resultRow].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[resultRow][mid] == target) {
                return true;
            }
            else if (matrix[resultRow][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
