///*
//This is a very good example of how easily memory can get corrupted.
//This example demonstrates that you should take extra care when having classes that allocate dynamic memorries.
//Especial care should be given to the cases where the objects of this class are being copied!
//This can be either with Copy Constructor or with assigning. The Copy Constructor gets called whenever
//we create a copy of the object for instance in case of passing the parameter with values.
//*/
//
//
//
//
//
//
//
//#include <iostream>
//using namespace std;
//
//#define DEFAULT_SIZE 10
//
//class invalid_operation_ex {};
//
//class stack {
//public:
//	stack(int size);
//	~stack();
//	stack(const stack &s); //Copy Constructor
//	stack(stack&& s); // Move Constructor
//	void push(int x);
//	void pop();
//	int top() const;
//	int elem_count() const { return count; }
//
//	stack& operator= (const stack& s); //Copy assignment
//	stack& operator= (stack&& s); //Move assignment
//	
//
//private:
//	int *elements;
//	int size;
//	int count;
//};
//
//stack::stack(int s = DEFAULT_SIZE) {
//	cout << "--constructor called\n";
//	size = s;
//	elements = new int[size];
//	count = 0;
//}
//
////Copy Constructor
//stack::stack(const stack &s)
//{
//	cout << "--copy contsructor is called" << endl;
//	//The new object which is copied from "s" will have the following members;
//	size = s.size;
//	count = s.count;
//	elements = new int[size];
//
//	for (int i = 0; i < size; ++i)
//		elements[i] = s.elements[i];
//
//}
//
////Move constructor
//stack::stack(stack&& s)
//{
//	cout << "--move constructor is called" << endl;
//	size = s.size;
//	count = s.count;
//	elements = s.elements;
//	s.elements = nullptr;
//}
//
// //if you define this as void ... then the assignement w = u = v won't work! since u = v does not return an object to put in w.
//stack& stack::operator=(const stack& s)
//{
//	cout << "--operator= is called." << endl;
//	if (this == &s) //this is self assignement, u = u, if we don't do this, then at the lines below we delete the buffer first and try to copy the elements, 
//		return *this;
//
//	size = s.size;
//	count = s.count;
//	delete[] elements; //since the left and right objects can have different stack sizes, we have to release the current one and then build a new buffer
//	elements = new int[size];
//
//	for (int i = 0; i < size; ++i)
//		elements[i] = s.elements[i];
//
//	return *this;
//}
//
//stack& stack::operator=(stack&& s)
//{
//	cout << "--opeartor= move assignment is called." << endl;
//	
//	if (this == &s)
//		return *this;
//
//	size = s.size;
//	count = s.count;
//	delete[] elements;
//	elements = s.elements;
//	s.elements = nullptr;
//
//	return *this;
//}
//
//
//stack::~stack() {
//	cout << "--destructor called\n";
//	delete[] elements;
//}
//
//void stack::push(int x) {
//	if (count >= size)
//		throw invalid_operation_ex();
//
//	elements[count] = x;
//	count++;
//}
//
//void stack::pop() {
//	if (count > 0)
//		count--;
//	else
//		throw invalid_operation_ex();
//}
//
//int stack::top() const {
//	if (count > 0)
//		return elements[count - 1];
//	else
//		throw invalid_operation_ex();
//}
//
//
//
//void print_stack(stack s) {
//	while (s.elem_count() > 0) {
//		cout << s.top() << ' ';
//		s.pop();
//	}
//	cout << endl;
//}
//
//stack create_stack(int i)
//{
//	stack s;
//	s.push(i + 30);
//	s.push(i + 31);
//	s.push(i + 32);
//
//	//Here both the move constructor and the destructor will get called. 
//	//Move constructor will get called to move the created object to 
//	//the return and don't copy everything and destructor will get called to destroy the object s
//	//If we don't have a move constructor, then the extensive copy constructor will get called.
//
//	return s; 
//}
//
//
//int main() {
//
//	stack u;
//	u.push(4);
//	u.push(5);
//	u.push(12);
//	print_stack(u);
//
//	stack v = u; // == stack v(u) since this is initialization, the copy constructor gets called here not assignment operator
//	stack w;
//	w = v; //this equals w.operator=(v)
//
//	stack k;
//	k.push(30);
//	k.push(31);
//	k.push(32);
//
//	print_stack(create_stack(4));
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
//////MICROSOFT WEBSITE EXAMPLE
////
////
////// MemoryBlock.h  
////// rvalue-references-move-semantics.cpp  
////// compile with: /EHsc  
////#include <vector>  
////#include "iostream"
////#include <algorithm>
////
////class MemoryBlock
////{
////public:
////
////	// Simple constructor that initializes the resource.  
////	explicit MemoryBlock(size_t length)
////		: _length(length)
////		, _data(new int[length])
////	{
////		std::cout << "In MemoryBlock(size_t). length = "
////			<< _length << "." << std::endl;
////	}
////
////	// Destructor.  
////	~MemoryBlock()
////	{
////		std::cout << "In ~MemoryBlock(). length = "
////			<< _length << ".";
////
////		if (_data != nullptr)
////		{
////			std::cout << " Deleting resource.";
////			// Delete the resource.  
////			delete[] _data;
////		}
////
////		std::cout << std::endl;
////	}
////
////
////
////	// Copy assignment operator.  
////	MemoryBlock& operator=(const MemoryBlock& other)
////	{
////		std::cout << "In operator=(const MemoryBlock&). length = "
////			<< other._length << ". Copying resource." << std::endl;
////
////		if (this != &other)
////		{
////			// Free the existing resource.  
////			delete[] _data;
////
////			_length = other._length;
////			_data = new int[_length];
////			for (int i = 0; i < _length; ++i)
////				_data[i] = other._data[i];
////		}
////		return *this;
////	}
////
////	// Move constructor.  
////	MemoryBlock(MemoryBlock&& other)
////		: _data(nullptr)
////		, _length(0)
////	{
////		std::cout << "In MemoryBlock(MemoryBlock&&). length = "
////			<< other._length << ". Moving resource." << std::endl;
////
////		// Copy the data pointer and its length from the   
////		// source object.  
////		_data = other._data;
////		_length = other._length;
////
////		// Release the data pointer from the source object so that  
////		// the destructor does not free the memory multiple times.  
////		other._data = nullptr;
////		other._length = 0;
////	}
////
////	// Move assignment operator.  
////	MemoryBlock& operator=(MemoryBlock&& other)
////	{
////		std::cout << "In operator=(MemoryBlock&&). length = "
////			<< other._length << "." << std::endl;
////
////		if (this != &other)
////		{
////			// Free the existing resource.  
////			delete[] _data;
////
////			// Copy the data pointer and its length from the   
////			// source object.  
////			_data = other._data;
////			_length = other._length;
////
////			// Release the data pointer from the source object so that  
////			// the destructor does not free the memory multiple times.  
////			other._data = nullptr;
////			other._length = 0;
////		}
////		return *this;
////	}
////
////	// Retrieves the length of the data resource.  
////	size_t Length() const
////	{
////		return _length;
////	}
////
////private:
////	size_t _length; // The length of the resource.  
////	int* _data; // The resource.  
////};
////
////
////
////
////
////int main()
////{
////	// Create a vector object and add a few elements to it.  
////	std::vector<MemoryBlock> v;
////	v.push_back(MemoryBlock(25));
////	v.push_back(MemoryBlock(75));
////
////	// Insert a new element into the second position of the vector.  
////	v.insert(v.begin() + 1, MemoryBlock(50));
////}