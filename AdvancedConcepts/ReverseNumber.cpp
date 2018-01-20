//#include "iostream"
//#include <algorithm>
//#include <vector>
//
//int rev_ext(int iNumber, int iReversed)
//{
//	if (iNumber == 0)
//	{
//		return iReversed;
//	}
//
//	iReversed = iReversed * 10 + iNumber % 10;
//	return rev_ext(iNumber / 10, iReversed);
//
//}
//
//
//int Reverse_Not_Recursive(int iNum)
//{
//	int reveresed_num = 0;
//
//	while (iNum > 0)
//	{
//		reveresed_num = reveresed_num * 10 + (iNum % 10);
//		iNum = iNum / 10;
//	}
//
//	return reveresed_num;
//}
//
//int Reverse_Recursive(int number)
//{
//	return rev_ext(number, 0);
//}
//
//int main()
//{
//	int iNum = 351;	
//	int iT = 0;
//	
//	//int iT = Reverse_Not_Recursive(iNum);
//	while (std::cin >> iNum)
//		std::cout << Reverse_Recursive(iNum) << std::endl;
//
//	std::cin.get();
//}
