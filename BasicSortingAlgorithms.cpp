/*
Sorting Alogorithms
Bubble Sort:
	Best: Omega(n) Average: Theta(n^2) Worst: O(n^2)
	Performs maximum number of swaps

Insertion Sort:
	Best: Omega(n) Average: Theta(n^2) Worst: O(n^2)
	Performs well on partially sorted array

Selection Sort:
	Best: Omega(n^2) Average: Theta(n^2) Worst: O(n^2)
	Minimum number of swaps, max is n

Counting Sort:
	Best: Omega(n+k) Average: Theta(n+k) Worst: O(n+k)

Preference:
	Counting > Insertion = Selection > Bubble
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v)
{
	cout << "[ ";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << "]" << endl;
}


vector<int> bubbleSort(const vector<int>& A)
{
	cout << "Bubble Sort" << endl << endl;
	int mainLoopIterations = 0;
	int innerLoopIterations = 0;

	vector <int> v(A);
	int temp = 0;
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		++mainLoopIterations;
		print(v);
		for (unsigned int j = 1; j < v.size() - i; ++j)
		{
			++innerLoopIterations;
			if (v[j] < v[j - 1])
			{
				temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;
			}
		}
		print(v);
		cout << endl;
	}
	cout << "mainLoopIterations: " << mainLoopIterations << endl;
	cout << "innerLoopIterations: " << innerLoopIterations << endl;
	cout << "Total iterations: " << mainLoopIterations + innerLoopIterations << endl << endl;
	return v;
}


vector<int> insertionSort(const vector<int>& A)
{
	cout << endl << endl << "Insertion sort" << endl << endl;
	int mainLoopIterations = 0;
	int innerLoopIterations = 0;

	vector<int> v(A);
	int key = 0, j = 0;
	for (unsigned int i = 1; i < v.size(); ++i)
	{
		mainLoopIterations++;
		key = v[i];
		j = i - 1;
		cout << "key: " << key << " i: " << i << " j: " << j << endl;
		print(v);
		for ( ; j >= 0 && v[j] > key; --j)
		{
			innerLoopIterations++;
			v[j + 1] = v[j];
		}
		v[j + 1] = key;
		print(v);
		cout << endl;
	}
	cout << "mainLoopIterations: " << mainLoopIterations << endl;
	cout << "innerLoopIterations: " << innerLoopIterations << endl;
	cout << "Total iterations: " << mainLoopIterations + innerLoopIterations << endl << endl;
	return v;
}


vector<int> selectionSort(const vector<int>& A)
{
	cout << endl << endl << "Selection sort" << endl << endl;
	int mainLoopIterations = 0;
	int innerLoopIterations = 0;

	vector<int> v(A);
	unsigned int minIndex = 0;
	int temp = 0;
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		mainLoopIterations++;
		minIndex = i;
		print(v);
		for (unsigned int j = i + 1; j < v.size(); ++j)
		{
			innerLoopIterations++;
			if (v[j] < v[minIndex])
			{
				minIndex = j;
			}
		}
		temp = v[minIndex];
		v[minIndex] = v[i];
		v[i] = temp;
		print(v);
		cout << endl;
	}
	cout << "mainLoopIterations: " << mainLoopIterations << endl;
	cout << "innerLoopIterations: " << innerLoopIterations << endl;
	cout << "Total iterations: " << mainLoopIterations + innerLoopIterations << endl << endl;
	return v;
}


vector<int> countingSort(const vector<int>& A)
{
	cout << endl << endl << "Counting sort" << endl << endl;
	int mainLoopIterations = 0;
	int countLoopIterations = 0;

	vector<int> v(A);
	vector<int> out(A.size(), 0);

	//find max in input array
	int max = v[0];
	for (unsigned int i = 1; i < v.size(); ++i)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
	}
	vector<int> count(max + 1, 0);

	//count the number of times a particular element is repeated
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		++count[v[i]];
	}

	//Based on count now we know which element needs how many places in out array
	//and prefix sum will tell the last index to store them
	for (unsigned int i = 1; i < count.size(); ++i)
	{
		countLoopIterations++;
		count[i] += count[i - 1];
	}

	//traverse the input array and based on prefix values fill out array
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		mainLoopIterations++;
		out[count[v[i]] - 1] = v[i];
		--count[v[i]];
	}

	cout << "mainLoopIterations: " << mainLoopIterations << endl;
	cout << "countLoopIterations: " << countLoopIterations << endl;
	cout << "Total iterations: " << mainLoopIterations + countLoopIterations << endl << endl;
	return out;
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int arr[] = { 5, 16, 3, 0, 8, -1 };
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	//int arr[] = { 0,5,3,3,8,1,1,2,9,1,2 };
	//int arr[] = { 8, 2, 3, 4, 7, 9 };

	vector <int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	print(bubbleSort(v));
	print(selectionSort(v));
	print(insertionSort(v));
	print(countingSort(v));
    return 0;
}

