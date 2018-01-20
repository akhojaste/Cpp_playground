//#include "iostream"
//#include <string>
//#include <math.h>
//
//using namespace std;
//
////This is a classic example of Dynamic Binding. As we know in polymorphism we do dynamic binding
////To figure our which class function we should call, either the child one or the parrent one.
////However Dynamic Binding requires some virtual memory allocation to have a map of the children classes
////and to know which function to call. Static Binding resolves this problem.
//
//
////class Animal
////{
////public:
////
////	Animal(){ cout << "Animal is created." << endl; }
////
////	virtual void eat()
////	{ 
////		cout << "Animal is eating." << endl;
////	}
////
////
////};
////
////class Dog : public Animal
////{
////public: 
////	Dog() 
////	{
////		cout << "Dog is created." << endl;
////	}
////
////	void eat() override
////	{
////		cout << "Dog is eating." << endl;
////	}
////};
////
////int main()
////{
////	Animal *pAnimal = new Dog();
////
////	pAnimal->eat();
////
////	cin.get();
////
////	//return 0; //you can bypass this return ONLY for main
////}
//
//
////Static Binding or Static Polymorphism
//template<class T>
//
//class Animal
//{
//public:
//
//	Animal(){ cout << "Animal is created." << endl; }
//
//	void eat()
//	{
//		static_cast<T*>(this)->eat();
//	}
//
//
//};
//
//class Dog : public Animal<Dog>
//{
//public:
//	Dog()
//	{
//		cout << "Dog is created." << endl;
//	}
//
//	void eat()
//	{
//		cout << "Dog is eating." << endl;
//	}
//};
//
//int main()
//{
//
//	double dbAngle = atan2(24, 28) * 180 / 3.1415;
//
//	Animal<Dog> *pAnimal = new Dog();
//
//	pAnimal->eat();
//
//	cin.get();
//
//	delete pAnimal;
//
//	//return 0; //you can bypass this return ONLY for main
//}