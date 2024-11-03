#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main()
{
	int N = 0, Q = 0;

	std::cin >> N >> Q;

	std::vector<int> weights(N);
	for (int i = 0; i < N; i++) {
		std::cin >> weights[i];
	}

	std::sort(weights.begin(), weights.end());

	int lowerBound = 0;
	int upperBound = 0;
	for (int i = 0; i < Q; i++) {
		std::cin >> lowerBound >> upperBound;
		if (upperBound < lowerBound) {
			std::cout << 0 << std::endl;
		}
		else {
			std::cout << std::upper_bound(weights.begin(), weights.end(), upperBound) - std::lower_bound(weights.begin(), weights.end(), lowerBound) << std::endl;
		}
	}
}