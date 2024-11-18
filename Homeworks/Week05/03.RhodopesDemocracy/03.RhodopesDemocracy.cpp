#include <iostream>
#include <stack>
#include <queue>
#include <list>

void fight(std::stack<int>& burevo, std::queue<int>& sredec, std::vector<int>& res) {
	int i, j;
	while (!burevo.empty() && !sredec.empty())
	{
		i = burevo.top();
		j = abs(sredec.front());

		if (i < j) {
			burevo.pop();
		}
		else if (i > j)
		{
			sredec.pop();
		}
		else
		{
			burevo.pop();
			sredec.pop();
		}
	}

	while (!sredec.empty()) {
		res.push_back(sredec.front());
		sredec.pop();
	}
}

void print(std::stack<int>& burevo, std::vector<int>& res)
{
	if (burevo.empty())
	{
		return;
	}

	int top = burevo.top();
	burevo.pop();
	print(burevo, res);

	res.push_back(top);
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int N = 0;
	std::cin >> N;

	std::stack<int> burevo;
	std::queue<int> sredec;
	std::vector<int> res;


	int curr = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> curr;

		if (burevo.empty() && curr < 0) {
			res.push_back(curr);
		}
		else if (!burevo.empty() && curr < 0) {
			sredec.push(curr);
		}
		else if (sredec.empty() && curr > 0) {
			burevo.push(curr);
		}
		else {
			fight(burevo, sredec, res);
			burevo.push(curr);
		}
	}

	if (!sredec.empty() && !burevo.empty()) {
		fight(burevo, sredec, res);
	}

	if (sredec.empty()) {
		print(burevo, res);
	}
	else
	{
		while (!sredec.empty()) {
			res.push_back(sredec.front());
			sredec.pop();
		}
	}

	if (res.empty()) {
		std::cout << '\n';
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			std::cout << res[i] << " ";
		}
	}
}