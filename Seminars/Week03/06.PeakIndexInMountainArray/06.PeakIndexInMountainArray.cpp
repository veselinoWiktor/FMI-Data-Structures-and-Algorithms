#include <iostream>
#include <vector>

int peakIndexInMountainArrayRecursion(std::vector<int>& arr, int left, int right) {
    if (left == right)
        return left;

    int mid = left + (right - left) / 2;
    int leftIdx = peakIndexInMountainArrayRecursion(arr, left, mid);
    int rightIdx = peakIndexInMountainArrayRecursion(arr, mid + 1, right);
    return arr[leftIdx] >= arr[rightIdx] ? leftIdx : rightIdx;
}

int peakIndexInMountainArray(std::vector<int>& arr) {
    return peakIndexInMountainArrayRecursion(arr, 1, arr.size() - 2);
}

int peakIndexInMountainArrayBinary(std::vector<int>& arr) {
    int l = 1; // because arr[0] and arr[n - 1] cannot be peaks
    int r = arr.size() - 2;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1]) {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int peakIndexInMountainArrayTernary(std::vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] < arr[mid2])
            l = mid1 + 1;
        else
            r = mid2 - 1;
    }
}

    int main()
{
}
