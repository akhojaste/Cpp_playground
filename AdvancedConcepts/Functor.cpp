/////**** FUNCTORS and OPERATOR OVERLOADING *****
//
//#include "iostream"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//
////class rectangle
////{
////private:
////	int iH;
////	int iW;
////
////public:
////	rectangle(int iHeight = 1, int iWidth = 1) : iH(iHeight), iW(iWidth){}
////	~rectangle(){};
////
////	double operator()(int iHeight, int iWidth); //overloading this operator makes this object to act like a function, hence will make it FUNCTOR
////	
////	void operator+ (rectangle rect);
////
////	void getH(int *piHeight);
////
////	void rectangle::operator= (rectangle rect);
////
////};
////
////
////double rectangle::operator()(int iHeight, int iWidth)
////{
////	return iHeight * iWidth;
////}
////
////
////
////void rectangle::getH(int *piHeight)
////{
////	piHeight = &this->iH;
////}
////
////void rectangle::operator+(rectangle rect)
////{
////	this->iH += rect.iH;
////	this->iW += rect.iW;
////}
////
////void rectangle::operator= (rectangle rect)
////{
////	this->iH = rect.iH;
////	this->iW = rect.iW;
////	
////}
////
////int main(int argc, char * argv[])
////{
////	rectangle rect1; // 1, 1
////	rectangle rect2(2, 3); // 2, 3
////
////	//Functor
////	std::cout << rect1(3, 4) << ", " << rect2(5, 6) << "\n";
////
////
////	rect1 = rect2;
////
////	std::cin.get();
////}
//
//class Complex
//{
//public:
//	
//	Complex(double r, double j) : m_dbReal(r), m_dbImg(j) {};
//	Complex() : m_dbReal(0.0), m_dbImg(0.0){};
//	double get_real() { return this->m_dbReal; };
//	double get_img() { return this->m_dbImg; };
//	
//	//Functor
//	double operator()() 
//	{ 
//		return m_dbReal;
//	}
//	Complex operator=(Complex c);
//
//private:
//	double m_dbReal;
//	double m_dbImg;
//
//};
//
//
//std::ostream& operator<<(std::ostream& output, Complex c)
//{
//	output << c.get_real();
//	if (c.get_img() > 0)
//	{
//		output << " -";
//	}
//	else
//	{
//		output << " +";
//	}
//
//	output << 'j' << c.get_img();
//	
//	return output;
//}
//
//
//Complex Complex::operator=(const Complex c)
//{
//	Complex out;
//
//	out.m_dbImg = c.m_dbImg;
//	out.m_dbReal = c.m_dbReal; 
//	
//	return out;
//}
//
//int main()
//{
//	Complex a(1.3, 2);
//	std::cout << a << std::endl;;
//
//	std::cout << a() << std::endl;
//
//	Complex b(4, 5);
//
//	Complex c = (a = b); // since a = b returns a Complex object, then c becoms the output of this operation, meaning that b will be outputed to c.
////	a.operator=(b);     // also a = b is eaual to 	a.operator=(b);
//
//
//	std::cin.get();
//}