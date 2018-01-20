//#include "iostream"
//#include <memory>
//
//using namespace std;
//
//class MyObject
//{
//public:
//	MyObject(int i) : m_iSize(i)
//	{
//		cout << "--Constructor is called" << endl;
//		m_pdbBuffer = new double[m_iSize];
//	}
//	~MyObject() 
//	{
//		cout << "--Destructor is called" << endl;
//		delete m_pdbBuffer;
//	}
//
//	int getSize() { return m_iSize; }
//
//	//Copy Constructor
//	MyObject(const MyObject& mOb);
//
//private:
//	int m_iSize;
//	double *m_pdbBuffer;
//};
//
//MyObject::MyObject(const MyObject& mOb)
//{
//	m_iSize = mOb.m_iSize;
//	m_pdbBuffer = new double[mOb.m_iSize];
//
//	for (int i = 0; i < m_iSize; ++i)
//		m_pdbBuffer[i] = mOb.m_pdbBuffer[i];
//}
//
//void f()
//{
//	std::unique_ptr<MyObject> pMy(new MyObject(4));
//	cout << pMy->getSize() << endl;
//}
//
//int main()
//{
//
//	f();
//
//	cin.get();
//}