#include <iostream>
#include <vector>

bool attacked(int i, int j, const auto& board, int N)
{
	// checking for column j
	for (int k {1}; k <= i - 1; ++k)
	{
		if (board.at(k).at(j) == 1)
			return false;
	}

	// checking upper right diagonal
	for (int k {i - 1}, l {j + 1}; k >= 1 && l <= N; ++k, ++l)
	{
		if (board.at(k).at(l) == 1)
			return false;
	}
	
	// checking for upper left diagonal
	for (int k {i - 1}, l {j - 1}; k >= 1 && l >= 1; --k, --l)
	{
		if (board.at(k).at(l) == 1)
			return false;
	}

	return true;
}

bool nqueen(int row, int n, int N, auto& board)
{
	if (n == 0)
		return false;

	for (int j {1}; j <= N; ++j)
	{
		if (attacked(row, j, board, N))
		{
			board.at(row).at(j) = 1;

			if (nqueen(row+1, n - 1, N, board))
				return false;

			board.at(row).at(j) = 0;	// backtracking
		}
	}

	return true;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<std::vector<T>>& board)
{
	for (const auto& row : board)
	{
		for (const auto& col : row)
		{
			out << col << " ";
		}
		out << std::endl;
	}

	return out;
}

int main(int argc, char** argv)
{
	auto n { std::stoi(argv[1]) };

	/*int **board = new int* [n];
	for (std::size_t i {}; i < n; ++i)
	{
		board[i] = new int[n];
	}*/

	auto board { std::vector<std::vector<int>>(n+1, std::vector<int>(n+1, 0)) };

	if(nqueen(1, n, n, board))
	{
		std::cout << board << std::endl;
	}

	/*for (std::size_t i {}; i < n; ++i)
	{
		delete[] board[i];
	}

	delete[] board;*/

	return 0;
}
