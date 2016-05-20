/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>


void spiral_add(int rowindex, int columnindex, int rows, int columns, int** input_array, int option, int *result, int len)
{
	if (rowindex == rows || columnindex == columns)
	{
		return;
	}
	else
	{
		switch (option)
		{
		case 1:
		{
			int i = columnindex;
			while (i<columns)
			{
				result[len++] = input_array[rowindex][i++];
			}
			//cout << "sg1  " << result[len - 1] << "  " << input_array[rowindex][i - 1] << "  " << rowindex << " " << i << " " << input_array[0][0];
			//display(result, len);
			spiral_add(rowindex + 1, columnindex, rows, columns, (int**)input_array, 2, result, len);
			break;
		}
		case 2:
		{
			int i = rowindex;
			while (i<rows)
			{
				result[len++] = input_array[i++][columns - 1];
			}
			//cout << "sg2  " << result[len - 1] << "  " << input_array[rowindex][i - 1] << "  " << rowindex << " " << i << " " << input_array[0][0];
			//display(result, len);
			spiral_add(rowindex, columnindex, rows, columns - 1, (int**)input_array, 3, result, len);
			break;
		}
		case 3:
		{
			int i = columns - 1;
			while (i >= columnindex)
			{
				result[len++] = input_array[rows - 1][i--];
			}
			//cout << "sg3  " << result[len - 1] << "  " << input_array[rowindex][i - 1] << "  " << rowindex << " " << i << " " << input_array[0][0];
			//display(result, len);
			spiral_add(rowindex, columnindex, rows - 1, columns, (int**)input_array, 4, result, len);
			break;
		}
		case 4:
		{
			int i = rows - 1;
			while (i >= rowindex)
			{
				result[len++] = input_array[i--][columnindex];
			}
			//cout << "sg4  " << result[len - 1] << "  " << input_array[rowindex][i - 1] << "  " << rowindex << " " << i << " " << input_array[0][0];
			//display(result, len);
			spiral_add(rowindex, columnindex + 1, rows, columns, (int**)input_array, 1, result, len);
			break;
		}
		default:return;
		}
	}
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	int *arr = (int*)malloc(sizeof(int)*rows*columns);
	spiral_add(0, 0, rows, columns, (int**)input_array, 1, arr, 0);
	return arr;
}
