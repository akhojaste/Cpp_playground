//#include "iostream"
//#include <string>
//
//using namespace std;
//
//class Shape
//{
//public: 
//	Shape() { cout << "--Shape::Constructor" << endl;  };
//	virtual ~Shape() { cout << "--Shape::Destructor" << endl; };
//
//};
//
//
//class Square : public Shape
//{
//public:
//	Square() { cout << "--Square::Constructor" << endl; }
//	~Square() { cout << "--Square::Destructor" << endl; }
//};
//
//
//
//int main()
//{
//	//We construct a Square object here, Since Square is derived 
//	//from Shape, we first build a Shape
//	Shape *pShape = new Square(); 
//	 
//	// Here we delete the object pShape is pointing to. Since it is of type Shape, 
//	//then we call the Shape destructor only. If we want to call the Square destructor 
//	//too we have make the base destructor to be virtual
//	delete pShape; 
//
//	cin.get();
//
//}