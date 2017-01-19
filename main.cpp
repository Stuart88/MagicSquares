#include <iostream>
#include "function.h"
#include <math.h>
#include <limits>

int main()
{
	std::ofstream MagicSquareOutput;
	std::ofstream SquareofSquares;

	MagicSquareOutput.open("MagicSquares.txt");
	SquareofSquares.open("MagicSquareofSquares.txt");
	
	squareofsquares(SquareofSquares, 100, 100, 100);
	magicsquare(MagicSquareOutput, 20, 20, 20);

	MagicSquareOutput.close();
	SquareofSquares.close();

	return 0;
}
