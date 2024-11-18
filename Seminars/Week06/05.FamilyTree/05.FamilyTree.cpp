#include <iostream>
#include <vector>

std::vector<int> nodes[1000001];
int inTimes[1000001]{ 0 };
int outTimes[1000001]{ 0 };

int ttime = 0;

void countingDFS(int v) {
	inTimes[v] = ttime++;

	for (auto x : nodes[v])
		countingDFS(x);

	outTimes[v] = ttime++;
}

int main()
{
	int N = 0;
	std::cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;
		nodes[a].push_back(b);
	}

	countingDFS(0);

	std::cin >> N;
	std::vector<std::string> ans;
	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;

		if (inTimes[a] < inTimes[b] && outTimes[a] > outTimes[b]) ans.push_back("YES\n");
		else ans.push_back("NO\n");
	}

	for (int i = 0; i < N; i++) std::cout << ans[i];

	return 0;
}
