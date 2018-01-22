/*
"this" pointer is a constant pointer pointing to the class. 
we can't change the value of "this" inside the class cause "this"
is constnt pointer. 

class example
{
	......

	void foo(example *p)
	{
		this = p; // this results in compile error since this is constant pointer.
	}

};

The ‘this’ pointer is passed as a hidden argument to all nonstatic member 
function calls and is available as a local variable within the body of all 
nonstatic functions. ‘this’ pointer is a constant pointer that holds the memory 
address of the current object. ‘this’ pointer is not available in static member 
functions as static member functions can be called without any object (with class name).
For a class X, the type of this pointer is ‘X* const’. Also, if a member function 
of X is declared as const, then the type of this pointer is ‘const X *const’ (see this GFact)

Following are the situations where ‘this’ pointer is used:

*/

//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//	Test &setX(int a) { x = a; return *this; }
//	Test &setY(int b) { y = b; return *this; }
//	void print() { cout << "x = " << x << " y = " << y << endl; }
//};
//
//int main()
//{
//	Test obj1(5, 5);
//
//	// Chained function calls.  All calls modify the same object
//	// as the same object is returned by reference
//	obj1.setX(10).setY(20);
//
//	obj1.print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//	void setX(int a) { x = a; }
//	void setY(int b) { y = b; }
//	void destroy() { delete this; }
//	void print() { cout << "x = " << x << " y = " << y << endl; }
//};
//
//int main()
//{
//	Test obj;
//	obj.destroy();
//	obj.print();
//	return 0;
//}

//PREDICT THE OUTPUT OF THE FOLLLOWING PROGRAMS

//Question 1
//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//public:
//	Test(int x = 0) { this->x = x; }
//	//void change(Test *t) { this = t; } //Compile error
//	void print() { cout << "x = " << x << endl; }
//};
//
//int main()
//{
//	Test obj(5);
//	Test *ptr = new Test(10);
//	//obj.change(ptr);
//	obj.print();
//	return 0;
//}

//Question 2
//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//	static void fun1() { cout << "Inside fun1()"; }
//	//static void fun2() { cout << "Inside fun2()"; this->fun1(); }//Compile error, cannot use 'this' inside static functions
//};
//
//int main()
//{
//	Test obj;
//	//obj.fun2();
//	return 0;
//}

//Question 3
//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//	
//	//Copy consturctor. Uncomment this function to see it gets hit.
//	//Test(const Test &t)
//	//{
//	//	this->x = t.x;
//	//	this->y = t.y;
//	//}
//
//	//This function returns a new object, so it first creates that object
//	//and the copies the current object into it.
//	Test setX(int a) { x = a; return *this; }
//
//	//This function returns a new object, so it first creates that object
//	//and the copies the current object into it.
//	Test setY(int b) { y = b; return *this; }
//
//	void print() { cout << "x = " << x << " y = " << y << endl; }
//};
//
//int main()
//{
//	Test obj1;
//	obj1.setX(10).setY(20);
//	obj1.print();
//	return 0;
//}

//Question 4
//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//	void setX(int a) { x = a; }
//	void setY(int b) { y = b; }
//	void destroy() { delete this; } //Run time error
//	void print() { cout << "x = " << x << " y = " << y << endl; }
//};
//
//int main()
//{
//	Test obj;
//	obj.destroy();
//	obj.print();
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
public:
	void fun()
	{
		delete this;
	}
};

int main()
{
	/* Following is Valid */
	A *ptr = new A;
	ptr->fun();
	ptr = nullptr; // make ptr NULL to make sure that things are not accessed using ptr. 


	 /* And following is Invalid: Undefined Behavior */
	A a;
	a.fun();

	getchar();
	return 0;
}

/*
Smart pointers. The way the unary operations (* and ->) are overloaded. 
*/

//#include<iostream>
//using namespace std;
//
//class testSmartPtr
//{
//	int x = 0;
//
//public:
//	testSmartPtr()
//	{
//		std::cout << "testSmartPtr::testSmartPtr()" << std::endl;
//	}
//	~testSmartPtr()
//	{
//		std::cout << "testSmartPtr::~testSmartPtr()" << std::endl;
//	}
//
//	void setX(int a)
//	{
//		x = a;
//	}
//
//	void printX()
//	{
//		std::cout << x << std::endl;
//	}
//
//};
//
//
//// A generic smart pointer class
//template <class T>
//class SmartPtr
//{
//	T *ptr;  // Actual pointer
//public:
//	// Constructor
//	//Refer https ://www.geeksforgeeks.org/g-fact-93/
//	explicit SmartPtr(T *p = NULL) { ptr = p; }
//
//	// Destructor
//	~SmartPtr() { delete(ptr); }
//
//	// Overloading dereferncing operator
//	T & operator * () { return *ptr; }
//
//	// Overloding arrow operator so that members of T can be accessed
//	// like a pointer (useful if T represents a class or struct or 
//	// union type)
//	T * operator -> () { return ptr; }
//};
//
//int main()
//{
//	SmartPtr<int> ptr(new int());
//	*ptr = 20;
//
//	SmartPtr<testSmartPtr> ptr2(new testSmartPtr);
//	ptr2->setX(13);
//	ptr2->printX();
//
//	cout << *ptr << std::endl;;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//class test
//{
//public:
//	test()
//	{
//		std::cout << "test::test()" << std::endl;
//	}
//
//	~test()
//	{
//		std::cout << "test::~test()" << std::endl;
//	}
//};
//
//int &fun()
//{
//	//Since the variable x is statitc, its initialization only gets called once
//	//And then x sticks around till the then of program. Refer to the object test
//	static int x = 10;
//	static test t;
//	return x;
//}
//int main()
//{
//	fun() = 30;
//	cout << fun();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
///*
//Once fun() returns, the space allocated to it on stack frame will be taken back. 
//So the reference to a local variable will not be valid.
//*/
//int &fun()
//{
//	int x = 10;
//	return x;
//}
//int main()
//{
//	fun() = 30;
//	cout << fun();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
    //This is de-refercing a null pointer and it will fail.
//	int *ptr = NULL;
//	int &ref = *ptr;
//	cout << ref;
//}

//#include<iostream>
//using namespace std;
//
//void swap(char * &str1, char * &str2)
//{
//	char *temp = str1;
//	str1 = str2;
//	str2 = temp;
//}
//
//int main()
//{
//	char *str1 = "GEEKS";
//	char *str2 = "FOR GEEKS";
//	swap(str1, str2);
//	cout << "str1 is " << str1 << endl;
//	cout << "str2 is " << str2 << endl;
//	return 0;
//}

// #include<iostream>
//using namespace std;
//
//int &fun()
//{
//	static int x = 10;
//	return x;
//}
//int main()
//{
//	fun() = 30;
//	cout << fun();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int fun(int &x)
//{
//	return x;
//}
//int main()
//{
//	cout << fun(10);
//	return 0;
//}