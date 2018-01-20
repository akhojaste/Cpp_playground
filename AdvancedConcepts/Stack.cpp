//#include <iostream>
//
////-- Stack implementation, it takes integers
//class IntStack{
//	int maxStackLength;
//	int* stack;
//public:
//	int stackIndex;
//	IntStack(int StackSize);
//	~IntStack();
//	void push(int num);
//	int pop();
//	int top();
//	int getSize();
//	bool isempty();
//	bool isFull();
//};
//
//IntStack::IntStack(int StackSize){
//	this->maxStackLength = StackSize;
//	stack = new int[this->maxStackLength];
//	this->stackIndex = 0;
//}
//
//IntStack::~IntStack(){
//	delete[] this->stack;
//}
//
//void IntStack::push(int num){
//	stack[this->stackIndex] = num;
//	++stackIndex;
//}
//
//int IntStack::pop(){
//	--stackIndex;
//	return stack[stackIndex];
//}
//
//int IntStack::top(){
//	return stack[stackIndex - 1];
//}
//
//int IntStack::getSize(){
//	return this->stackIndex;
//}
//
//
//bool IntStack::isempty(){
//
//	return this->stackIndex == 0 ? true : false;
//}
//
//bool IntStack::isFull(){
//
//	return this->stackIndex == this->maxStackLength ? true : false;
//}
//
//
//int main(int argc, char* argv[])
//{
//
//	IntStack myStack(5);
//
//	std::cout << myStack.isempty() << std::endl;
//
//	std::cout << myStack.getSize() << std::endl;
//	std::cout << myStack.isFull() << std::endl;
//
//	myStack.push(1);
//	myStack.push(2);
//	myStack.push(3);
//	myStack.push(4);
//	myStack.push(5);
//
//	std::cout << myStack.getSize() << std::endl;
//
//	std::cout << myStack.isempty() << std::endl;
//
//	for (int i = 0; i < 5; ++i){
//		std::cout << myStack.pop() << std::endl;
//	}
//
//	std::cout << myStack.isempty() << std::endl;
//
//	return 0;
//
//}