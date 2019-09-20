#include <iostream>
using namespace std;
const int ROW = 3;
const int COL = 3;
bool isMagic(int array[ROW][COL]);

int main()
{
	int myArray[ROW][COL] = { {8,1,6}, {3,5,7}, {4,2,2} };
	if (isMagic(myArray))
		cout << "its magic!!" << endl;
	else
		cout << "not magic" << endl;
	system("pause");
	return 0;
}


bool isMagic(int array[ROW][COL])
{
	int sum = 0;
	int comparisonSum = 0;
	int r, c;

	// add each row
	for (r = 0; r < ROW; r++)
	{
		for (c = 0; c < COL; c++)
		{
			sum += array[r][c];
		}
		if (comparisonSum == 0)
			comparisonSum = sum;
		else if (comparisonSum != sum)
			return false;
		sum = 0;
	}

	// check each column
	for (c = 0; c < COL; c++)
	{
		for (r = 0; r < ROW; r++)
		{
			sum += array[r][c];
		}
		
		if (comparisonSum != sum)
			return false;
		sum = 0;
	}
	// checks one diagonal
	for (r = 0; r < ROW; r++)
	{
		sum += array[r][r];
	}
	if (comparisonSum != sum)
		return false;
	sum = 0;

	// check other diagonal
	r = 0;
	c = 2;
	for (; r < ROW; r++)
	{
		sum += array[r][c];
		c--;
	}
	if (comparisonSum != sum)
		return false;

	return true;
}