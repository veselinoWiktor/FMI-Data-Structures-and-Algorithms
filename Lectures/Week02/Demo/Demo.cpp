#include <iostream>
#include <algorithm>
#include <vector>

// O(n^2)
void bubbleSort(std::vector<int>& arr)
{
	bool isSwapped = false;

	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		isSwapped = false;

		for (size_t j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
		{
			return;
		}
	}
}

void selectionSort(std::vector<int>& arr) {
	size_t n = arr.size();

	for (size_t i = 0; i < n - 1; i++) {
		size_t min = i;

		for (size_t j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			std::swap(arr[i], arr[min]);
		}
	}
}


void insertionSort(std::vector<int>& arr)
{
	int n = arr.size();

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void merge(std::vector<int>& arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];

	for (int i = 0; i < n2; i++)
		R[i] = arr[middle + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k] = L[i++];

		else
			arr[k] = R[j++];

		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int>& arr, int left, int right) {
	if (left >= right)
		return;

	int middle = left + (right - left) / 2;
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, middle, right);
}

int partition(std::vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	}

	std::swap(arr[i], arr[high]);
	return i;
}

void quickSort(std::vector<int>& arr, int low, int high) {
	if (low >= high)
		return;

	int p = partition(arr, low, high);
	quickSort(arr, low, p - 1);
	quickSort(arr, p + 1, high);
}

void conting_sort(char arr[], int n) {
	char* arr_copy = new char[n];
	for (int i = 0; i < n; ++i) {
		arr_copy[i] = arr[i];
	}
	int* count = new int[256];
	for (int i = 0; i < n; ++i) {
		count[arr[i]] = count[arr[i]] + 1;
	}
	for (int i = 1; i <= 255; ++i) {
		count[i] += count[i - 1];
	}
	// To make it stable we are operating in reverse order.
	for (int i = n - 1; i >= 0; i--) {
		arr[count[arr_copy[i]] - 1] = arr_copy[i];
		count[arr_copy[i]] = count[arr_copy[i]] - 1;
	}
}

void printArr(const std::vector<int>& arr)
{
	size_t n = arr.size();

	for (size_t i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}