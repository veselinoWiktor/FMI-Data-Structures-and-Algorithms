#include <iostream>
#include <deque>
#include <vector>

void printKMinSum(std::vector<int>& vec, int K)
{
	std::deque<int> window;

	int i = 0;
	for (; i < K; i++) {

		while (!window.empty() && vec[i] <= vec[window.back()])
		{
			window.pop_back();
		}

		window.push_back(i);
	}

	long long sum = vec[window.front()];
	for (; i < vec.size(); i++) {

		while (!window.empty() && window.front() <= i - K)
		{
			window.pop_front();
		}

		while (!window.empty() && vec[i] <= vec[window.back()])
		{
			window.pop_back();
		}

		window.push_back(i);
		sum += vec[window.front()];
	}

	std::cout << sum;
}

int main()
{
	int N = 0, K = 0;
	std::cin >> N >> K;

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> vec[i];
	}

	printKMinSum(vec, K);
}