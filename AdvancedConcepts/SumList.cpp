////**** Sum of the list *****
//#include "iostream"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//int SumList(std::vector<int> &vecNums, int iSize);
//
//int main(int argc, char * argv[])
//{
//
//	std::vector<int> vecNums(5);
//
//	int iSize = 0;
//	std::cin >> iSize;
//
//	vecNums.resize(iSize);
//
//	for (int i = 0; i < iSize; ++i)
//		vecNums[i] = i + 1;
//
//	int iSum = SumList(vecNums, iSize);
//
//	std::cout << iSum << "\n";
//
//	system("pause");
//}
//
//int SumList(std::vector<int> &vecNums, int iSize)
//{
//	if (iSize == 1)
//		return vecNums[0];
//
//	int iSumNMinus1 = SumList(vecNums, iSize - 1);
//
//	return iSumNMinus1 + vecNums[iSize - 1];
//
//}