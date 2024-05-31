

#define N 4
#include <stdbool.h>
#include <stdio.h>

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j])
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int duprow = row;
	int dupcol = col;

	while (row >= 0 && col >= 0)
	{
		if (board[row][col] == 1)
			return false;
		row--;
		col--;
	}

	col = dupcol;
	row = duprow;
	while (col >= 0)
	{
		if (board[row][col] == 1)
			return false;
		col--;
	}

	row = duprow;
	col = dupcol;
	while (row < N && col >= 0)
	{
		if (board[row][col] == 1)
			return false;
		row++;
		col--;
	}
	return true;
}

bool solveNQUtil(int board[N][N], int col)
{

	if (col >= N)
		return true;

	for (int i = 0; i < N; i++)
	{

		if (isSafe(board, i, col))
		{

			board[i][col] = 1;

			if (solveNQUtil(board, col + 1))
				return true;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return false;
}

bool solveNQ()
{
	int board[N][N] = {{0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0}};

	if (solveNQUtil(board, 0) == false)
	{
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}
