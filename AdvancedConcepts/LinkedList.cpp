///**
//* A sample code of removing a node from a linked list.
//* In this examples, we try to remove a node with a given value from
//* a linked list if it exists.
//*/
//
//#include <iostream>
//#include <cstddef>
//
//using std::cout;
//using std::endl;
//
///*
//A linked list is a list constructed using pointers. It is not fixed in
//size and could grow and shrink while the program is running.
//
//A typical defination of list nodes contains at least two parts, both the
//content or date of each element and the pointer to the next element,
//which is shown in the figure below.
//
//+---------+
//|  Data   | -----> holds the data of this element in the list.
//+---------+
//| pointer | -----> is a pointer to the next element in the list.
//+---------+
//
//***Attention***:
//The pointer holds the address of the next element, not the address of the
//data in the next element, even though they are the same in value sometimes.
//And It should be set to NULL while acting as the last node of the list.
//
//
//Implementation of the single linked list:
//+---------+    --->+---------+    --->+---------+
//|  Data   |    |   |  Data   |    |   |  Data   |
//+---------+    |   +---------+    |   +---------+
//| pointer |-----   | pointer |-----   | pointer |
//+---------+        +---------+        +---------+
//*/
//
//
///* definition of the list node class */
//class Node
//{
//	friend class LinkedList;
//private:
//	int _value; /* data, can be any data type, but use integer for easiness */
//	Node *_pNext; /* pointer to the next node */
//
//public:
//	/* Constructors with No Arguments */
//	Node(void)
//		: _pNext(NULL)
//	{ }
//
//	/* Constructors with a given value */
//	Node(int val)
//		: _value(val), _pNext(NULL)
//	{ }
//
//	/* Constructors with a given value and a link of the next node */
//	Node(int val, Node* next)
//		: _value(val), _pNext(next)
//	{}
//
//	/* Getters */
//	int getValue(void)
//	{
//		return _value;
//	}
//
//	Node* getNext(void)
//	{
//		return _pNext;
//	}
//};
//
///* definition of the linked list class */
//class LinkedList
//{
//private:
//	/* pointer of head node */
//	Node *_pHead;
//	/* pointer of tail node */
//	Node *_pTail;
//
//public:
//	/* Constructors with a given value of a list node */
//	LinkedList(int val);
//	LinkedList() {};
//	/* Destructor */
//	~LinkedList(void);
//
//	/* Function to append a node to the end of a linked list */
//	void tailAppend(int val);
//
//	/* Remove a node with a specific value if it exists */
//	void remove(int val);
//
//	/* Traversing the list and printing the value of each node */
//	void traverse_and_print();
//
//	/* Function to delete all the elements of a linked list */
//	void clear();
//
//	void Reverse();
//
//	void Push(int newData);
//};
//
//LinkedList::LinkedList(int val)
//{
//	/* Create a new node, acting as both the head and tail node */
//	_pHead = new Node(val);
//	_pTail = _pHead;
//}
//
//LinkedList::~LinkedList()
//{
//	clear();
//
//	/*
//	* Leave it empty temporarily.
//	* It will be described in detail in the example "How to delete a linkedlist".
//	*/
//}
//
//
//void LinkedList::tailAppend(int val)
//{
//	Node *newNode = new Node;
//	newNode->_value = val;
//
//	newNode->_pNext = nullptr;
//
//	_pTail->_pNext = newNode;
//
//	_pTail = newNode;
//}
//
//
////void LinkedList::tailAppend(int val)
////{
////	/* The list is empty? */
////	if (_pHead == NULL) {
////		/* the same to create a new list with a given value */
////		_pTail = _pHead = new Node(val);
////	}
////	else
////	{
////		/* Append the new node to the tail */
////		_pTail->_pNext = new Node(val);
////		/* Update the tail pointer */
////		_pTail = _pTail->_pNext;
////	}
////}
//
//void LinkedList::remove(int val)
//{
//	Node *current = _pHead;
//	Node *prev = current;
//
//	//if it is the head node it should be treated especially because there is no prev node
//	if (_pHead->_value == val)
//	{
//		prev = _pHead;
//		_pHead = _pHead->_pNext;
//
//		delete prev;
//
//		return;
//	}
//
//	while (current != nullptr)
//	{
//		if (current->_value == val)
//		{
//			break;
//		}
//		else
//		{
//			prev = current;
//			current = current->_pNext;
//		}
//
//	}
//
//	prev->_pNext = current->_pNext;
//
//	delete current;
//
//
//}
//
//
//void LinkedList::traverse_and_print()
//{
//	Node *current = _pHead;
//
//	if (_pHead == nullptr)
//		cout << "List is empty!" << endl;
//
//	while (current != nullptr)
//	{
//		cout << current->_value << " ";
//		current = current->_pNext;
//	}
//	cout << endl;
//}
//
//
////void LinkedList::traverse_and_print()
////{
////	Node *p = _pHead;
////
////	/* The list is empty? */
////	if (_pHead == NULL) {
////		cout << "The list is empty" << endl;
////		return;
////	}
////
////	cout << "LinkedList: ";
////	/* A basic way of traversing a linked list */
////	while (p != NULL) { /* while there are some more nodes left */
////		/* output the value */
////		cout << p->_value << " ";
////		/* The pointer moves along to the next one */
////		p = p->_pNext;
////	}
////	cout << endl;
////}
//
//void LinkedList::clear()
//{
//	Node *current = _pHead;
//	Node *prev = current;
//
//	while (current != nullptr)
//	{
//		_pHead = current->_pNext;
//		prev = current;
//
//		current = current->_pNext;
//
//		delete prev;
//	}
//
//	_pHead = _pTail = nullptr;
//}
//
////void LinkedList::clear()
////{
////	Node *pDel = _pHead;
////
////	/* Traverse the list and delete the node one by one from the head */
////	while (pDel != NULL) {
////		/* take out the head node */
////		_pHead = _pHead->_pNext;
////		delete pDel;
////		/* update the head node */
////		pDel = _pHead;
////	}
////	/* Reset the head and tail node */
////	_pTail = _pHead = NULL;
////}
//
//void LinkedList::Reverse()
//{
//	Node *current = _pHead;
//	Node *prev = nullptr;
//	Node *next = current;
//	
//	_pTail = _pHead;
//	
//	while (current != nullptr)
//	{
//		next = current->_pNext;
//		current->_pNext = prev;
//		prev = current;
//		current = next;
//	}
//
//	_pHead = prev;
//
//}
//
//
//void LinkedList::Push(int newData)
//{
//	Node *newNode = new Node(newData);
//	newNode->_pNext = _pHead;
//	_pHead = newNode;
//}
//
//int main(int argc, const char * argv[])
//{
//	/* Create a list with only one node */
//	LinkedList list;
//	///* Append 3 nodes to the end of the list */
//	//list.tailAppend(2);
//	//list.tailAppend(3);
//	//list.tailAppend(4);
//
//	list.Push(1);
//	list.Push(2);
//	list.Push(3);
//	list.Push(4);
//
//
//	cout << "Before removing: " << endl;
//	/* output the result */
//	list.traverse_and_print();
//
//	list.Reverse();
//
//	cout << "Reversed List " << endl;
//	list.traverse_and_print();
//
//	/* Remode the node with value 3 */
//	list.remove(2);
//	/* output the result */
//	cout << "After removing: " << endl;
//	list.traverse_and_print();
//
//	/* Output the result */
//	list.clear();
//	cout << "After clearing: " << endl;
//	list.traverse_and_print();
//
//
//	std::cin.get();
//
//	return 0;
//}