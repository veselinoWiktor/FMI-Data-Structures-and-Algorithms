#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool isValid(std::vector<int>& arr, long long mid, int T) {
    long long currentSum = 0;
    int teamCount = 1;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        if (currentSum > mid) {
            teamCount++;
            currentSum = arr[i];
        }
    }

    if (teamCount <= T) return true;
    else return false;
}

int separateTeams(std::vector<int>& arr, int T) {
    long long l = *std::max_element(arr.begin(), arr.end());
    long long r = std::accumulate(arr.begin(), arr.end(), 0ll);

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (isValid(arr, mid, T)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return l;
}

int main()
{
    int N = 0, T = 0;
    std::cin >> N >> T;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::cout << separateTeams(arr, T);
}