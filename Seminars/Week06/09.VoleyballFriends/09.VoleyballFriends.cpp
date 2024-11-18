#include <iostream>
#include <set>

int main()
{
	std::set<int> voleyballTeam;

	int first;
	std::cin >> first;

	voleyballTeam.insert(first);

	int Q;
	std::cin >> Q;
	int a, b;
	for (int i = 0; i < Q; i++)
	{
		std::cin >> a >> b;
		if (voleyballTeam.count(a) == 1) {
			voleyballTeam.insert(b);
		}

	}

	std::cout << voleyballTeam.size();
}