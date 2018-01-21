/* A program with compilation error to demonstrate that Final class cannot
be inherited */
#include<iostream>
using namespace std;

/*

How to make the "final" class in C++. i.e a class that is not inheritable.
A class that if you try to inherit from it, you will get a compilation error.
In the code below, class Final is not inheritable. 

Notes about class the below code:

1 - class Final is a friend of class MakeFinal. Because of this, Final can
access to private and protected members of MakeFinal. Whewn constructor of
Final gets called, we also want to call the constructor of MakeFinal. If Final
is not a friend of MakeFInal, it can't call its private constructor.

2 - MakeFinal is a virtual base class. Because of this, Derived and Final
have to share the same instance of MakeFinal. Also, the constructor of MakeFinal
is called through constructor of Derived, NOT Final. (Just like the Diamond problem
where the constructor of grandparrent class is called through constructor of grandchildren 
class.) Genrally, the constructor of a virtual base class is not called by the class 
that inherits from it, instead the constructor is called by the constructor of the 
concrete class. Now, since Derived is not a friend of MakeFinal, it cannot call it 
and hence we will get a compile erro.

3 - There are many other ways of creating a Final class. If FInal is not a friend of
MakeFinal, then no one can inherit from MakeFinal whos constructor is private. Also
becauese of virtual inheritance, anotehr way to do this is to get rid of default
constructor for the MakeFinal class. Since in virtual inheritance, only the default
constructor gets calle unless it is specified explicitly in the grandchildren class.

*/



class Final; // The class to be made final

class MakeFinal // used to make the Final class final
{
private:
	MakeFinal() { cout << "MakFinal constructor" << endl; }
	friend class Final;
};

class Final : virtual public MakeFinal
{
public:
	Final() { cout << "Final constructor" << endl; }
};



class Derived : public Final // Compiler error
{
public:
	Derived() { cout << "Derived constructor" << endl; }
};

int main(int argc, char *argv[])
{
	Derived d;
	return 0;
}
