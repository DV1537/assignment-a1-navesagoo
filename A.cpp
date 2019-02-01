#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */

int main(int argc, const char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ifstream inputData;
	double * arr;
	int size = 0;
	int index = 0;
	double sum = 0;
	double average = 0;
	inputData.open(argv[1]);
	if (inputData.is_open())
	{
		cout << "Input: ";
		while (inputData.peek() != EOF) // While not reached end of file, increase size
		{
			double x = 0;
			inputData >> x;
			size++;
			sum += x;
			cout << x << " ";
		}
		if (size == 0)
		{
			cout << "No numbers in input!";
			return -2;
		}
		arr = new double[size];
		inputData.close();
		inputData.open(argv[1]);
		while (inputData.peek() != EOF) // While not reached end of file, copy next number.
		{
			inputData >> arr[index];
			index++;
		}

		inputData.close();

		average = sum / index;
		cout << "  Output:  ";

		for (int i = 0; i < index; i++)
		{
			if (arr[i] > average)
			{
				cout << arr[i] << " ";
			}

		}
		delete[] arr;
	}
	else
	{
		cout << "Unable to open file!";
		return -1;
	}
	return 0;
}

