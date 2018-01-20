//#include "iostream"
//#include <string>
//#include <exception>
//
//using namespace std;
//
////Example 1
//class Exception_Type2
//{
//public:
//	Exception_Type2(std::string str) : m_strError(str) {}
//	~Exception_Type2(){};
//
//	std::string what(){ return m_strError; }
//
//private:
//	std::string m_strError;
//};
//
//
//class Exception_Type1
//{
//public:
//	Exception_Type1(){ std::cout << "An Error has occures, check your argument."; };
//	Exception_Type1(std::string s);
//	~Exception_Type1(){};
//
//	std::string what() { return m_strError; };
//
//private:
//	std::string m_strError;
//	
//};
//
//Exception_Type1::Exception_Type1(std::string s)
//{
//	m_strError = s;
//}
//
//class Student
//{
//public:
//	Student() : m_iStudentNumber(0) {};
//	Student(int iNumber) : m_iStudentNumber(iNumber) {};
//	~Student(){};
//
//	int do_something(int iTest);
//
//private:
//	int m_iStudentNumber;
//};
//
//int Student::do_something(int iTest)
//{
//	
//	std::cout << "case " << iTest << std::endl;
//		
//	switch (iTest)
//	{
//	case 0:
//		throw Exception_Type1("Exception_Type1 is thrown.");
//		break;
//	case 1:
//		throw Exception_Type2("Exception_Type2 is thrown.");
//		break;
//	case 2:
//		throw "something bas has happpend.";
//		break;
//	}
//
//
//	
//
//}
//
//void heyhey()
//{
//	Student s;
//
//	try
//	{
//		int ii = s.do_something(3);
//	}
//	catch (Exception_Type1 bA)
//	{
//		std::cout << bA.what() << std::endl;
//		throw;
//	}
//	catch (Exception_Type2 eT2)
//	{
//		std::cout << eT2.what() << std::endl;
//	}
//	catch (...)
//	{
//		std::cout << "default exception" << std::endl;
//	}
//}
//
//int main()
//{
//
//	try
//	{
//		heyhey();
//	}
//	catch (Exception_Type1 bA)
//	{
//		std::cout << "main has also received the exception" << std::endl;
//	}
//
//
//	
//	
//	std::cin.get();
//
//}
//
//
//// Example 2
////void foo()
////{
////	std::cout << 1 << std::endl;
////	throw std::exception();
////	std::cout << 4;
////}
////
////int main()
////{
////
////
////	try
////	{
////		foo();
////	}
////	catch (std::exception e)
////	{
////		std::cout << e.what() << std::endl;
////	}
////
////	std::cout << 3;
////
////	std::cin.get();
////}
//
//
//
//////Example 3
////
////using namespace std;
////
////void h() 
////{ 
////	cout << 5; 
////	throw exception(); 
////	cout << 6; 
////}
////
////void g() 
////{ 
////	cout << 3; 
////	h(); 
////	cout << 4; 
////}
////
////int main() {
////	
////	try { 
////		cout << 1; 
////		g(); 
////		cout << 2; 
////	}
////	catch (exception ex) 
////	{ 
////		cout << 7;
////	} 
////	
////	cout << 8;
////
////	cin.get();
////}