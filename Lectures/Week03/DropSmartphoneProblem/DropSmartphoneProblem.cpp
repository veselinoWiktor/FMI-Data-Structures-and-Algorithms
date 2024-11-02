#include <iostream>

/*
Имаме 2 еднакви смартфона и 100 етажна сграда. С колко най-малко опита
може да се намери най-ниския етаж, на който смартфона ще се счупи при
падане? ЗАБЕЛЕЖКА: При пускане на един смартфон от даден етаж, той или
се счупва или не понася никакви поражения
*/


const int MIN_FLOOR = 0;
const int MAX_FLOOR = 100;

int findBreakingFloor(int floor, bool& isFound) {
	//int jump = sqrt(100); // because 100 floors
	isFound = false;
	int jump = 14;
	int start = 0;
	int end = start + jump;
	int steps = MIN_FLOOR;

	while (end < MAX_FLOOR && end <= floor) {
		steps++;
		start = end;
		end += --jump;

		if (end > MAX_FLOOR)
			end = MAX_FLOOR;
	}

	for (int i = start; i <= end; i++) {
		steps++;
		if (i == floor)
		{
			isFound = true;
			break;
		}
	}

	return steps;
}

int main()
{
	bool found = 0;
	std::cout << findBreakingFloor(2, found);
	std::cout << " " << found;
}

