///*
//In Win32 we use events and then WaitForSingleObject or WaitForMultipleObjects
//to synchronize the execution of threads. C++11 introduced Conditional Variables.
//It is exactly the same concept as events. One thread will signal it and the other
//thread will wait for it. 
//
//With Conditional Variables, we sould always use std::unique_lock and we in fact
//can't use std::lock_guard. std::unique_lock has all the functionalities of 
//std::lock_guard. It locks the mutex in constructor and unlocks it in destructor.
//In addition, you can also lock and unlock the mutex manually too. 
//In std::lock_guard you can't do this. Basically std::unique_lock is a better
//class of std::lock_guard. Thats's it. More information can be found here:
//http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html
//
//*/
//
//#include "iostream"
//#include <condition_variable>
//#include <thread>
//#include <vector>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex mu; //Global mutex;
//std::vector<int> Vals(10, 0); //Shared resource
//std::condition_variable cond; //The conditional variable or event
//
//void ThreadWorker1(int &k)
//{
//	k = 12;
//	std::unique_lock<std::mutex> ul(mu);
//	
//	//Some processing here that takes some time
//	//To simulate that I just slepp this thread for some time
//
//	std::cout << "Thread is doing some work." << std::endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	std::cout << "Thread is signalling." << std::endl;
//	cond.notify_one();
//
//}
//
//int main(int argc, char *argv[])
//{
//
//	int x = std::thread::hardware_concurrency();
//	std::thread t1(ThreadWorker1, std::ref(x));
//	//t1.join(); //this means the main thread will wait for t1 to finish
//	t1.detach(); //this means that t1 will run freely on its own.
//
//	std::unique_lock<std::mutex> ul(mu);
//	cond.wait(ul, 
//		[]()
//		{
//			return !Vals.empty();
//		}
//	    ); //Lambda is for spurious wake i.e. wake by the same thread
//
//	std::cout << "Signal is received." << std::endl;
//
//	
//	std::cin.get();
//}