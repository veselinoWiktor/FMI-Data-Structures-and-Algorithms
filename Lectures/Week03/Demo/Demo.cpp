#include <iostream>
#include <vector>

/// <summary>
/// Best case O(1), Average case O(N), Worst case O(n)
/// </summary>
/// <param name="arr"></param>
/// <param name="length"></param>
/// <param name="x"></param>
/// <returns></returns>
int linear_search(int arr[], int length, int x) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

/// <summary>
/// Best case: O(1); Average case: O(Log2N); Worst case: O(Log2N)
/// </summary>
/// <param name="arr"></param>
/// <param name="l"></param>
/// <param name="r"></param>
/// <param name="x"></param>
/// <returns></returns>
int binary_search_iterative(const std::vector<int>& arr, int l, int r, int x) {
	while (r >= l) {
		int m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;
		else if (arr[m] < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	return -1;
}

/// <summary>
/// Best case: O(1); Average case: O(Log2N); Worst case: O(Log2N)
/// </summary>
/// <param name="arr"></param>
/// <param name="l"></param>
/// <param name="r"></param>
/// <param name="x"></param>
/// <returns></returns>
int binary_search_recursion(const std::vector<int>& arr, int l, int r, int x) {
	if (r < l) {
		return -1; // Not found
	}

	int m = l + (r - l) / 2;

	if (arr[m] == x) {
		return m;
	}
	else if (arr[m] < x) {
		return binary_search_recursion(arr, m + 1, r, x);
	}
	else {
		return binary_search_recursion(arr, l, m - 1, x);
	}
}

/// <summary>
/// Best case: O(N); Average case: O(Log3N); Worst case: O(Log3N)
/// </summary>
/// <param name="arr"></param>
/// <param name="l"></param>
/// <param name="r"></param>
/// <param name="x"></param>
/// <returns></returns>
int ternarySearch(const std::vector<int>& arr, int l, int r, int x) {
	while (r >= l) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		if (arr[mid1] == x) return mid1;
		if (arr[mid2] == x) return mid2;

		if (arr[mid1] > x) {
			r = mid1 - 1;
		}
		else if (arr[mid2] < x) {
			l = mid2 + 1;
		}
		else {
			r = mid2 - 1;
			l = mid1 + 1;
		}
	}
	return -1;
}

/// <summary>
/// Best case: O(1); Average case: O(sqrt(N)); Worst case: O(sqrt(N))
/// </summary>
/// <param name="arr"></param>
/// <param name="x"></param>
/// <param name="steps"></param>
/// <returns></returns>
int jump_search(const std::vector<int>& arr, int x, int& steps) {
	int len = arr.size();
	int jump = sqrt(len);
	int start = 0, end = start + jump;

	while (end < len && arr[end] <= x) {
		steps++;
		start = end;
		end += jump;

		if (end > len - 1) {
			end = len;
		}
	}

	for (int i = start; i < end; i++) {
		steps++;
		if (arr[i] == x) {
			return i;
		}
	}

	return -1;
}

int main()
{
	std::vector<int> fib_seq = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };

	int steps = 0;
	int idx = jump_search(fib_seq, 144, steps);
	std::cout << idx << " " << steps;
}