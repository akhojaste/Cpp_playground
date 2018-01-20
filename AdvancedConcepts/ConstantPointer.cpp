//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//std::vector<int> vec;
//
////This funciton takes a pointer to a constant value
//void fun(const int *pInt)
//{
//	vec.push_back(*pInt);
//	std::cout << vec[0] << std::endl;
//}
//
//int main()
//{
//
//	int iT = 5;
//
//	fun(&iT); //Prints 5
//
//	iT = 6;
//
//	std::cout << vec[0] << std::endl; //Also prints 5, since the vector "vec" took the value of a pointer to constant values
//
//	cin.get();
//
//	return 0;
//
//}