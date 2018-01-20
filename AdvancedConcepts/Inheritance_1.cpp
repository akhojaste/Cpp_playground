//#include "iostream"
//#include <string> //so we can output string to the console
//
//using namespace std;
//
//class Person
//{
//public:
//	Person(string sN, string sNC) : sName(sN), sNat_Code(sNC){}
//	~Person();
//
//	string get_name(){ return sName; }
//	string get_NatCode(){ return sNat_Code; }
//
//private:
//
//	string sName;
//	string sNat_Code;
//
//};
//
//class Student : public Person
//{
//public:
//
//	Student(string sN, string sNC, string sSId) : Person(sN, sNC), sStudentID(sSId){} // this means to initialize the "Person" part of Student class with those parameter
//	string get_StudentID(){ return sStudentID; }
//
//private:
//	string sStudentID;
//
//};
//
//class Employee : public Person
//{
//public:
//
//	Employee(string sN, string sNC, string sEC, int iBS) : Person(sN, sNC), sEmp_Code(sEC), iBase_Salary(iBS){}
//	~Employee();
//
//	string get_emp_code(){ return sEmp_Code; }
//
//	int Calc_Salary(){ return 100; }
//
//private:
//	string sEmp_Code;
//	int iBase_Salary;
//};
//
//int main(int *argc, char *argv[])
//{
//
//
//	cin.get();
//	
//	//main can skip have no return!
//
//}