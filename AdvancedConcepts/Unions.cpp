//#include "iostream"
//#include <string>
//using namespace std;
//
//
//class shape
//{
//public:
//	shape() {};
//	~shape() {};
//
//	virtual void scale() = 0;
//};
//
//class rect : public shape
//{
//public:
//	rect() {}; //OSKOL: Constructor needs to have implementation
//	~rect() {}; // OSKOL: Destructor needs to have implemetation
//
//	void scale() override;
//};
//
//void rect::scale()
//{
//	cout << "rect::scale" << endl;
//}
//
//union testUnion
//{
//	struct
//	{
//		unsigned Data : 8; //RW //lower bit
//		unsigned Addr : 8; //WO
//		unsigned BusyBus : 1; //RO
//		unsigned RW : 1; //WO
//		unsigned Reset : 1; //WO
//		unsigned TestMode : 1; //WO
//		unsigned NotUsed : 12; //Higher bit
//
//	};
//
//	int iVal;
//	
//};
//
//
//typedef enum Color
//{
//	RED = 0x001,
//	BLUE = 0x002,
//	GREEN = 0x004
//} ColorEnum;
//
//void main()
//{
//
//	////shape s; //Compile error
//	//rect r;
//
//	//testUnion tU = { 0 };
//	//tU.iVal = 0x1FF;
//	//cout << tU.Data << endl; // this is gonna be 0
//
//	for (int l = 0; l < 5; ++l)
//	{
//		int OffsetLine1 = (l / 3) * 12 + l %3;
//
//		std::cout << "Offset Line " << l << OffsetLine1 << std::endl;
//	}
//
//	cin.get();
//
//}