#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<bool>> initMatrix(int N, int M)
{
	std::vector<std::vector<bool>> res(N);
	for(int i = 0; i < N; i ++)
	{
		res[i] = std::vector<bool>(M);
		for(int j = 0; j < M; j++)
		{
			res[i][j] = false;
		}
	}

	return res;
}

bool isValidCoords(int x, int y, int N, int M)
{
	return 0 <= x && x < N
		&& 0 <= y && y < M;
}

void addApple(std::vector<std::vector<bool>>& matrix, std::queue<std::pair<int, int>>& apples, int appleX, int appleY)
{
	if (isValidCoords(appleX, appleY, matrix.size(), matrix[0].size())
		&& matrix[appleX][appleY] == false)
	{
		matrix[appleX][appleY] = true;
		apples.push(std::pair<int, int>(appleX, appleY));
	}
}

int main()
{
	int N = 0, M = 0, T = 0;
	std::cin >> N >> M >> T;


	std::vector<std::vector<bool>> matrix = initMatrix(N, M);

	std::queue<std::pair<int, int>> apples;
	int x = 0;
	int y = 0;

	while (std::cin >> x >> y)
	{
		std::pair<int, int> coords(x - 1, y - 1);
		matrix[x - 1][y - 1] = true;
		apples.push(coords);
	}

	int sum = apples.size();
	for(int i = 0; i < T; i++)
	{
		int currentCount = apples.size();
		while(currentCount > 0)
		{
			std::pair<int, int> currApple = apples.front();

			addApple(matrix, apples, currApple.first, currApple.second - 1);
			addApple(matrix, apples, currApple.first, currApple.second + 1);
			addApple(matrix, apples, currApple.first - 1, currApple.second);
			addApple(matrix, apples, currApple.first + 1, currApple.second);

			apples.pop();
			currentCount--;
		}
		sum += apples.size();
	}

	std::cout << N * M - sum;
}
