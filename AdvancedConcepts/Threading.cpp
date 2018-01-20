//#include "iostream"
//#include <thread>
//#include <ppl.h>
//#include <iostream>
//#include <random>
//#include <mutex>
//#include <string>
//
////Concurency::parallel_for example
////std::mutex mu;
////
////void print(size_t i)
////{
////	//We have to lock the "cout"since it is shared by various objects
////	std::lock_guard<std::mutex> m(mu);
////	std::thread::id ThreadId = std::this_thread::get_id();
////	std::cout << i << std::endl;
////}
////
////int main()
////{
////
////	const size_t nthreads = std::thread::hardware_concurrency();
////
////	concurrency::parallel_for(0, (int)nthreads,
////		////Lambda expression
////		[](size_t i)
////		{
////			//std::lock_guard<std::mutex> m(mu);
////			//std::thread::id ThreadId = std::this_thread::get_id();
////			//std::cout << "From Thread: " << ThreadId << " " << i << std::endl;
////
////			//or we can call it like this
////			print(i);
////		}
////			
////	);
////
////
////	std::cin.get();
////
////}
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
//
////MUTEX and LOCK OBJECTS
//
//std::mutex mu;
//
//void shared_print(std::string&  msg, int i)
//{
//	// Version 1, using lock() and unlock() directly
//	// using of lock() and unlock() is not good at all because the part of the code inside the critical section 
//	// can throw an exception and then we never release the lock! better to use local variable so when 
//	// they go out of scope, the lock gets released itself
//
//	//mu.lock();	
//	//cout << msg << i << endl;
//	//mu.unlock();
//
//	//Version 2, using local variables
//
//	//This is still bad!(why!!!) because cout is a global variable and is shared between threads!
//	std::lock_guard<std::mutex> gaurd(mu);
//	std::thread::id id = std::this_thread::get_id();
//	std::cout << msg << id << ',' << i << std::endl;
//
//}
//
//void print()
//{
//	std::string s = "from Thread: ";	
//	for (int i = 0; i < 10; ++i)
//	{
//		shared_print(s, i);
//	}
//
//}
//
//int main()
//{
//
//	std::thread t(print);
//	std::thread::id id = std::this_thread::get_id();
//
//	std::string s = "from Main: ";
//	for (int i = -10; i < 0; ++i)
//	{
//		shared_print(s, i);
//	}
//
//	
//	t.join();
//
//	std::cin.get();
//	return 0;
//}