//#include "iostream"
//#include <map>
//#include <string>
//#include <exception>
//#include <vector>
//#include <string>
//
//struct Comp
//{
//	bool operator() (int key1, int key2)
//	{
//		return key1 > key2;
//	}
//};
//
//
//void test(std::vector<std::string> &vec)
//{
//	vec.push_back("");
//	vec.push_back("1");
//	vec.push_back("2");
//	vec.push_back("3");
//}
//
//int main()
//{
//
//	try
//	{
//
//
//		std::vector<std::string> vec;
//		test(vec);
//
//
//		std::map<int, std::string, Comp> sMap;
//
//		sMap.insert(std::make_pair(3, "first"));
//		sMap.insert(std::make_pair(1, "second"));
//		sMap.insert(std::make_pair(2, "third"));
//		sMap.insert(std::make_pair(4, "forth"));
//		sMap.insert(std::make_pair(5, "fifth"));
//		sMap.insert(std::make_pair(6, "sixth"));
//
//		auto it = sMap.begin();
//		it = sMap.erase(it);
//
//	}
//	catch (std::exception e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	
//
//	return 0;
//}
//
