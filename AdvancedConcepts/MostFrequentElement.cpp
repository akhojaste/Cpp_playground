//#include "iostream"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//std::vector<int> most_freqenct(std::vector<int> nums);
//
//int main(int argc, char *argv[])
//{
//	double j = -8.0 / 5.0;
//
//	std::string current;
//	std::string previous = "";
//	
//	while (std::cin >> current)
//	{
//		if (previous == current)
//		{
//			std::cout << "put something new man!" << std::endl;
//		}
//		else
//		{
//			previous = current;
//		}
//	}
//
//	std::vector<std::vector<int>> vec2D(5, std::vector<int>(4, 6)); // 3 sets of vectors, each set has 4 values and all of them are 6
//
//	vec2D.resize(3);
//	vec2D[0].resize(3); 
//	vec2D[1].resize(1);
//	vec2D[2].resize(2);
//
//
//
//	std::vector<char> vecTempChars(26, 'A');
//
//	int iA = (int)vecTempChars[0];
//
//	for (int i = 1; i < vecTempChars.size(); ++i)
//	{
//		vecTempChars[i] = (char)(++iA);
//	}
//
//
//	std::vector<int> vecNums(10, 5);
//	
//	vecNums[0] = 1;
//	vecNums[1] = 12;
//	vecNums[2] = 11;
//	vecNums[3] = 11;
//	vecNums[4] = 4;
//	vecNums[5] = 6;
//	vecNums[6] = 4;
//	vecNums[7] = 6;
//	vecNums[8] = 4;
//	vecNums[9] = 6;
//
//	
//	std::vector<int> vecMostFrequent = most_freqenct(vecNums);
//
//	return 0;
//}
//
//std::vector<int> most_freqenct(std::vector<int> nums)
//{
//	std::vector<int> vecResult;
//
//	std::sort(nums.begin(), nums.end());
//
//	int iMaxIterGlobal(1);
//	int iCounter = 0;
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		iCounter = 0;
//
//		std::vector<int>::iterator itr = std::find(nums.begin(), nums.end(), nums[i]);
//		while (itr != nums.end())
//		{
//			++iCounter;
//			if (iCounter > iMaxIterGlobal)
//				iMaxIterGlobal = iCounter;
//			
//			++itr;
//			itr = std::find(itr, nums.end(), nums[i]);
//		}
//	}
//	int iMaxIter(1);
//	std::map<int, int> mapMostCommon;
//
//	for (int i = 0; i < nums.size() - 1; i += iMaxIter)
//	{
//		iMaxIter = 1;
//
//		if (nums[i + 1] != nums[i])
//			continue;
//
//		while (nums[i + iMaxIter] == nums[i])
//		{
//			++iMaxIter;
//		}
//
//		if (iMaxIter >= iMaxIterGlobal)
//		{
//			iMaxIterGlobal = iMaxIter;
//			mapMostCommon.insert(std::pair<int, int>(iMaxIterGlobal, nums[i]));
//		}
//
//		
//	}
//
//	std::map<int, int>::iterator mapitr = mapMostCommon.find(iMaxIterGlobal);
//
//	while ((mapitr = mapMostCommon.find(iMaxIterGlobal)) != mapMostCommon.end())
//	{
//		vecResult.push_back(mapitr->second);
//		++mapitr;
//	}
//
//
//	std::vector<int> vecMostFrequent(nums.size(), 0);
//	std::vector<int>::iterator itr;
//
//	int iMaxIterInx = 0;
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		itr = std::find(nums.begin(), nums.end(), nums[i]);
//
//		while (itr != nums.end())
//		{
//			++vecMostFrequent[i];
//			++itr;
//			itr = std::find(itr, nums.end(), nums[i]);
//		}
//
//		if (vecMostFrequent[i] > iMaxIterInx)
//		{
//			iMaxIterInx = vecMostFrequent[i];
//		}
//	}
//
//	std::vector<int>::iterator itr2 = std::find(vecMostFrequent.begin(), vecMostFrequent.end(), iMaxIterInx);
//
//	std::vector<int>::iterator itr3;
//
//	int iPos = 0;
//	while (itr2 != vecMostFrequent.end())
//	{
//		iPos = std::distance(vecMostFrequent.begin(), itr2);
//
//		if (iPos >= 0 && iPos < nums.size())
//		{ 
//			itr3 = std::find(vecResult.begin(), vecResult.end(), nums[iPos]);
//			if (itr3 == vecResult.end())
//				vecResult.push_back(nums[iPos]);
//		}
//			
//
//		++itr2;
//		itr2 = std::find(itr2, vecMostFrequent.end(), iMaxIterInx);
//	}
//
//	return vecResult;
//}