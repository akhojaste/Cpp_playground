////Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
////The constructors of inherited classes are called in the same order in which they are inherited.
////For example, in the following program, B’s constructor is called before A’s constructor.
////The destructors are called in reverse order of constructors.
//
////#include<iostream>
////using namespace std;
////
////class A
////{
////public:
////	A() { cout << "A's constructor called" << endl; }
////};
////
////class B
////{
////public:
////	B() { cout << "B's constructor called" << endl; }
////};
////
////class C : public B, public A  // Note the order
////{
////public:
////	C() { cout << "C's constructor called" << endl; }
////};
////
////int main()
////{
////	C c;
////	return 0;
////}
//
////For example, consider the following program.
//
////#include<iostream>
////using namespace std;
////class Person {
////	// Data members of person 
////public:
////	Person(int x) { cout << "Person::Person(int ) called" << endl; }
////};
////
////class Faculty : public Person {
////	// data members of Faculty
////public:
////	Faculty(int x) :Person(x) {
////		cout << "Faculty::Faculty(int ) called" << endl;
////	}
////};
////
////class Student : public Person {
////	// data members of Student
////public:
////	Student(int x) :Person(x) {
////		cout << "Student::Student(int ) called" << endl;
////	}
////};
////
////class TA : public Faculty, public Student {
////public:
////	TA(int x) :Student(x), Faculty(x) {
////		cout << "TA::TA(int ) called" << endl;
////	}
////};
////
////int main() {
////	TA ta1(30);
////}
//
////In the above program, constructor of ‘Person’ is called two times.
////Destructor of ‘Person’ will also be called two times when object ‘ta1’ 
////is destructed.So object ‘ta1’ has two copies of all members of ‘Person’, 
////this causes ambiguities.The solution to this problem is ‘virtual’ keyword.
////We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid 
////two copies of ‘Person’ in ‘TA’ class.For example, consider the following program.
//
////#include<iostream>
////using namespace std;
////class Person {
////public:
////	Person(int x) { cout << "Person::Person(int ) called" << endl; }
////	Person() { cout << "Person::Person() called" << endl; }
////};
////
////class Faculty : virtual public Person {
////public:
////	Faculty(int x) :Person(x) {
////		cout << "Faculty::Faculty(int ) called" << endl;
////	}
////};
////
////class Student : virtual public Person {
////public:
////	Student(int x) :Person(x) {
////		cout << "Student::Student(int ) called" << endl;
////	}
////};
////
////class TA : public Faculty, public Student {
////public:
////	TA(int x) :Student(x), Faculty(x) {
////		cout << "TA::TA(int ) called" << endl;
////	}
////};
////
////int main() {
////	TA ta1(30);
////}
//
//
////In the above program, constructor of ‘Person’ is called once.
////One important thing to note in the above output is, the default 
////constructor of ‘Person’ is called.When we use ‘virtual’ keyword, 
////the default constructor of grandparent class is called by default 
////even if the parent classes explicitly call parameterized constructor.
//////How to call the parameterized constructor of the ‘Person’ class ?
////The constructor has to be called in ‘TA’ class.For example, see the following program.
//
////#include<iostream>
////using namespace std;
////class Person {
////public:
////	Person(int x) { cout << "Person::Person(int ) called" << endl; }
////	Person() { cout << "Person::Person() called" << endl; }
////};
////
////class Faculty : virtual public Person {
////public:
////	Faculty(int x) :Person(x) {
////		cout << "Faculty::Faculty(int ) called" << endl;
////	}
////};
////
////class Student : virtual public Person {
////public:
////	Student(int x) :Person(x) {
////		cout << "Student::Student(int ) called" << endl;
////	}
////};
////
////class TA : public Faculty, public Student {
////public:
////	TA(int x) :Student(x), Faculty(x), Person(x) {
////		cout << "TA::TA(int ) called" << endl;
////	}
////};
////
////int main() {
////	TA ta1(30);
////}
//
////In general, it is not allowed to call the grandparent’s constructor directly, 
////it has to be called through parent class.It is allowed only when ‘virtual’ keyword is used.
////As an exercise, predict the output of following programs.
//
////**********************************************************************************************//
//////Question 1
////Predict the output of the followin program
////#include<iostream>
////using namespace std;
////
////class A
////{
////	int x;
////public:
////	A(int i) { x = i; }
////	void print() { cout << x; }
////};
////
////class B : virtual public A
////{
////public:
////	B() :A(10) {  }
////};
////
////class C : virtual public A
////{
////public:
////	C() :A(10) {  }
////};
////
////class D : public B, public C {
////};
////
////int main()
////{
////	D d;
////	d.print();
////	return 0;
////}
//
////#include<iostream>
////using namespace std;
////
////class A
////{
////	int x;
////public:
////	//Since this is virtual inheritance, only one copy of A will be created
////	//Also "Default Constructor" of A will be be called not the parameterized version.
////	//Parameterized version can be called, only directly from grandchildren constructor class
////	//i.e. constructor of class D here.
////	//So without the following line, the following program will have a compilation error.
////	//A() { x = 0; } 
////	A(int i) { x = i; }
////	void print() { cout << x; }
////};
////
////class B : virtual public A
////{
////public:
////	B() :A(10) {  }
////};
////
////class C : virtual public A
////{
////public:
////	C() :A(10) {  }
////};
////
////class D : public B, public C {
////};
////
////int main()
////{
////	D d;
////	d.print();
////
////	std::cout << std::endl;
////	std::cin.get();
////
////	return 0;
////}
//
//
/////Test 
//#include<iostream>
//using namespace std;
//
//class A
//{
//	int x;
//public:
//	//Since this is virtual inheritance, only one copy of A will be created
//	//Also "Default Constructor" of A will be be called not the parameterized version.
//	//Parameterized version can be called, only directly from grandchildren constructor class
//	//i.e. constructor of class D here.
//	//So without the following line, the following program will have a compilation error.
//	A() 
//	{ 
//		x = 0; 
//		std::cout << "A::A() is called." << std::endl;
//	} 
//	A(int i) 
//	{ 
//		x = i;
//		std::cout << "A::A(int) is called." << std::endl;
//	}
//	void print() 
//	{
//		std::cout << "A::print() is called." << std::endl;
//		cout << x;
//	}
//};
//
//class B : virtual public A
//{
//public:
//	B() :A(10) 
//	{ 
//		std::cout << "B::B() is called." << std::endl;
//	}
//};
//
//class C : virtual public A
//{
//public:
//	C() :A(100) 
//	{  
//		std::cout << "C::C() is called." << std::endl;
//	}
//};
//
//class D : virtual public A
//{
//public:
//	D() : A(1000) 
//	{
//		std::cout << "D::D() is called." << std::endl;
//	}
//};
//
//class E : public B, public C, public D
//{
//public:
//	E()
//	{
//		std::cout << "E::E() is called." << std::endl;
//	}
//
//	//If we want to call A(int), we can only do it from grand children's class
//	//E() : A(5)
//	//{
//	//	std::cout << "E::E() is called." << std::endl;
//	//}
//};
//
//int main()
//{
//	E e;
//	e.print();
//
//	std::cin.get();
//	return 0;
//}