//// ****** Hanoe Problem ******
//
//#include "iostream"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//void Hanoe(std::vector<int>& vecSourcePegs, std::vector<int>& vecDestPegs, std::vector<int>& vecSparePegs, int iSourcePegSize);
//
//int main(int argc, char *argv[])
//{
//	std::vector<int> vecSource;
//
//	int iSize = 0;
//	std::cin >> iSize;
//
//	for (int i = iSize; i >= 1; --i)
//		vecSource.push_back(i);
//
//	std::vector<int> vecDest;
//	std::vector<int> vecSpare;
//
//	Hanoe(vecSource, vecDest, vecSpare, vecSource.size());
//
//	for (int i = 0; i < vecDest.size(); ++i)
//	{
//		std::cout << vecDest[i] << " ,";
//	}
//
//	std::cout << "\n";
//	system("pause");
//
//}
//
//void Hanoe(std::vector<int>& vecSourcePegs, std::vector<int>& vecDestPegs, std::vector<int>& vecSparePegs, int iSourcePegSize)
//{
//	if (iSourcePegSize == 1)
//	{
//		vecDestPegs.push_back(vecSourcePegs.back());
//		vecSourcePegs.pop_back();
//		return;
//	}
//
//	Hanoe(vecSourcePegs, vecSparePegs, vecDestPegs, iSourcePegSize - 1); //move n-1 disks to the spare peg
//
//	//Move the one disk to the dest
//	vecDestPegs.push_back(vecSourcePegs.back());
//	vecSourcePegs.pop_back();
//
//	Hanoe(vecSparePegs, vecDestPegs, vecSourcePegs, iSourcePegSize - 1);
//
//}