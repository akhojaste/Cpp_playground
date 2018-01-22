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
//	void push(int x);
//	void pop();
//	int top() const;
//	int elem_count() const { return count; }
//
//	stack& operator= (const stack& s);
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
//void print_stack(stack s) {
//	while (s.elem_count() > 0) {
//		cout << s.top() << ' ';
//		s.pop();
//	}
//	cout << endl;
//}
//// if you define this as void ... then the assignement w = u = v won't work! since u = v does not return an object to put in w.
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
//int main() {
//	
//	stack u;
//	u.push(4);
//	u.push(5);
//	u.push(12);
//	print_stack(u);
//
//	// == stackv(u) since this is initialization, the copy constructor gets called here
//	//Since the initial state of the object is created using another object, then
//	//Copy constructor will get called.
//	stack v = u; 
//	stack w;
//	w = v; //this equals w.operator=(v)
//
//	print_stack(w);
//
//}