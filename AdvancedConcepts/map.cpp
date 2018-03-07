/*map vs unordered_map in C++

When it comes to efficiency, there is a huge difference between maps and unordered maps.
We must know the internal working of both to decide which one is to be used.

Difference :

					| map					| unordered_map
	-------------------------------------------------------- -
	Ordering		| increasing  order		| no ordering
					| (by default) |

	Implementation	| Self balancing BST	| Hash Table
					| like Red - Black Tree |

	search time		| log(n)				| O(1)->Average
					|						| O(n)->Worst Case

	Insertion time	| log(n) + Rebalance	| Same as search

	Deletion time	| log(n) + Rebalance	| Same as search

	Use std::map when
	You need ordered data.
	You would have to print / access the data(in sorted order).
*/
	// CPP program to demonstrate use of std::map
//#include "iostream"
//#include <map>
//
//	int main()
//{
//	// Ordered map
//	std::map<int, int> order;
//
//	// Mapping values to keys
//	order[5] = 10;
//	order[3] = 5;
//	order[20] = 100;
//	order[1] = 1;
//
//	// Iterating the map and printing ordered values
//	for (auto i = order.begin(); i != order.end(); i++) {
//		std::cout << i->first << " : " << i->second << '\n';
//	}
//  system("pause");
//}

/*
Use std::unordered_map when
You need to keep count of some data(Example – strings) and no ordering is required.
You need single element access i.e.no traversal.
*/
// CPP program to demonstrate use of 
#include "iostream"
#include <unordered_map>


int main()
{
	// Unordered map
	std::unordered_map<int, int> order;

	// Mapping values to keys
	order[5] = 10;
	order[3] = 5;
	order[20] = 100;
	order[1] = 1;

	// Iterating the map and printing unordered values
	for (auto i = order.begin(); i != order.end(); i++) {
		std::cout << i->first << " : " << i->second << '\n';
	}

	system("pause");
}