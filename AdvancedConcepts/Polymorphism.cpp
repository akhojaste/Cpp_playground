#include "iostream"
#include <string>
using namespace std;

//class Employee
//{
//public:
//	Employee(){}
//	~Employee(){}
//
//	void print_me();
//
//	virtual void print_something()
//	{ cout << "Employee" << endl;  }
//};
//
//void Employee::print_me()
//{
//	print_something();
//}
//
//class Student : public Employee
//{
//public:
//	Student(){}
//	~Student(){}
//
//	void print_something() 
//	{ cout << "Student" << endl; } 
//};
//
//void Print1(Employee p)
//{
//	p.print_something();
//}
//
//void Print2(Employee &p)
//{
//	p.print_something();
//}
//
//int main()
//{
//
//	Student s;
//	Employee &p1 = s;	
//	p1.print_something(); // prints "Student" p1 is a reference of s, so it is basically an s object. 
//	Print1(p1); //prints "Employee" because Print1 will do a local copy of the parameters since they are passed by value and not reference
//	Print2(p1); //prints "Student"
//
//	Employee p2 = s;
//
//	p2.print_something(); // "Employee"
//	Print1(p2); // "Employee"
//	Print2(p2); // Employee
//
//	cin.get();
//
//}

////example 2
//
//class A {
//public:
//	void f() { cout << "A::f" << endl; }
//	virtual void g() { cout << "A::g" << endl; }
//	void h() { cout << "A::h" << endl; f(); g(); }
//};
//
//class B : public A {
//public:
//	void f() { cout << "B::f" << endl; }
//	void g() { cout << "B::g" << endl; }
//	void h() { cout << "B::h" << endl; f(); g(); }
//};
//
//int main()
//{
//	A a;
//	B b;
//	A* ap = &b;
//	ap->f();
//	ap->g();
//	ap->h();
//
//	cin.get();
//
//}



//Howmany compile error you see here?
//#include <iostream>
//using namespace std;

//class A {
//public:
//	void f() { cout << "A::f"; }
//	virtual void g() = 0;
//	void h() { cout << "A::h"; f(); g(); }
//private:
//	int a;
//	void k() { cout << "A::k"; }
//};
//
//class B : public A {
//public:
//	int f() { cout << "B::f"; return 0; }
//	int f(int x) { return x + a; }
//	int k() { cout << "B::k"; }
//protected:
//	void h() { cout << "B::h"; }
//};
//
//class C : public A {
//public:
//	void g() { cout << "C::g"; }
//};
//
//int main() {
//	A a;
//	B b;
//	C c;
//	A* ap = &c;
//	ap->g();
//	B* bp = &c;
//	bp->g();
//}