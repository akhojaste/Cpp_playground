//#include "iostream"
//
//const int ROW = 8;
//const int COL = 8;
//const int iPossibleMoves = 8;
//const int ci_Row_Steps[iPossibleMoves] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//const int ci_Col_Steps[iPossibleMoves] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//
//int board[ROW][COL] = { 0 };
//
//
//bool find_tour(int iMoveNumber, int iCurrentRow, int iCurrentColomn)
//{
//	if (iMoveNumber == ROW * COL) // problem is solved!
//	{
//		return true;
//	}
//
//	int iNewRow, iNewCol = 0;
//	for (int iMove = 0; iMove < iPossibleMoves; ++iMove)
//	{
//		iNewRow = iCurrentRow + ci_Row_Steps[iMove];
//		iNewCol = iCurrentColomn + ci_Col_Steps[iMove];
//
//		//if outside of the boundry, its not valid
//		if (iNewCol >= COL || iNewCol < 0 || iNewRow >= ROW || iNewRow < 0) 
//			continue;
//
//		//if the board already have a value, again it is not valid
//		if (board[iNewRow][iNewCol] != 0)
//			continue;
//
//		board[iNewRow][iNewCol] = iMoveNumber + 1;
//
//		bool bIsNextTourValid = find_tour(iMoveNumber + 1, iNewRow, iNewCol);
//
//		if (bIsNextTourValid)
//		{
//			return true;
//		}
//		else
//		{
//			board[iNewRow][iNewCol] = 0;
//		}
//	}
//
//	return false;
//}
//
//
//void solve(int init_row, int init_col) {
//
//	for (int row = 0; row < ROW; row++)
//		for (int col = 0; col < COL; col++)
//			board[row][col] = 0;
//
//
//	board[init_row][init_col] = 1;
//	if (!find_tour(1, init_row, init_col))
//		std::cout << "Failed to find a tour!\n";
//}
//
//
//
//int main(int argc, char *argv[])
//{
//	solve(2, 3);
//
//	std::cin.get();
//}