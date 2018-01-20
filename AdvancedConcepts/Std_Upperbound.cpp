//#include "iostream"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//
//
////**** std::upper_bound
//bool Comp(const int& v1, const int& v2)
//{
//	return v1 <= v2;
//}
//
//int main(int argc, char *argv[])
//{
//
//	int i = (-1) / 2;
//
//	std::vector<int> vecTest(3);
//	vecTest[0] = -15;
//	vecTest[1] = 0;
//	vecTest[2] = 15;
//
//	std::vector<int>::iterator itr = std::upper_bound(vecTest.begin(), vecTest.end(), 0, [&](int x, int y) {return x < y; });
//
//	if (itr != vecTest.end())
//	{
//		int k = *itr;
//	}
//
//
//	return 0;
//}