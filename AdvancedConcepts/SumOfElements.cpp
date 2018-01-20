//#include "iostream"
//
//int sum_of_element(int iNum)
//{
//	int iT = 0;
//
//	iNum = std::abs(iNum);
//
//	if (iNum / 10 == 0) //iNum < 10
//	{
//		return iNum;
//	}
//
//	iT = iNum % 10 + sum_of_element(iNum / 10);
//
//	return iT;
//
//}
//
////int sum_of_element(int iNum)
////{
////	if (iNum < 1000)
////	{
////		int iT1 = iNum / 100; //3
////		iNum = iNum - iT1 * 100; //51
////		int iT2 = iNum / 10; //5
////		iNum = iNum - iT2 * 10; // 1
////		int iT3 = iNum;
////
////		return iT1 + iT2 + iT3;
////	}
////
////	return -1;
////}
//
//int main()
//{
//	int iNum;
//	
//	while(std::cin >> iNum)
//		std::cout << "Sum of elements is: " << sum_of_element(iNum) << std::endl;
//
//	std::cin.get();
//}
