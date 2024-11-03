#include <iostream>
#include <vector>
#include <algorithm>

long long puncakesCookingTime(std::vector<int>& chefs, long long N) {
    long long minTime = 0;
    long long maxTime = chefs[chefs.size() - 1] * N;

    while (minTime <= maxTime) {
        long long midTime = minTime + (maxTime - minTime) / 2;
        long long sum = 0;
        for (int i = 0; i < chefs.size(); i++) {
            sum += midTime / chefs[i];
        }

        if (sum >= N)
        {
            maxTime = midTime - 1;
        }
        else
        {
            minTime = midTime + 1;
        }
    }

    return minTime;
}

int main()
{
    long long N = 0;
    int K = 0;
    std::cin >> N >> K;

    std::vector<int> chefs(K);
    for (int i = 0; i < chefs.size(); i++) {
        std::cin >> chefs[i];
    }

    std::sort(chefs.begin(), chefs.end());

    std::cout << puncakesCookingTime(chefs, N);
}
