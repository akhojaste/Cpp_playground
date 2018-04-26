#include "iostream"
#include <algorithm>

using namespace std;

/*

Blob Counter.

Find the number of connected blobs within an image using the depth-first-search method.
The connectivity is defined as four way connetion. Can change to 8 way or something else.

*/


#define ROW 8
#define COL 16
#define CONNECTIVITY 4 //4 way connectivity.

// direction vectors
const int dx[CONNECTIVITY] = { +1, 0, -1, 0 };
const int dy[CONNECTIVITY] = { 0, +1, 0, -1 };

// the input image
int img[ROW][COL] = {	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }
				  };

// the labels, 0 means unlabeled
int label[ROW][COL] = { 0 };

void depth_first_search(int x, int y, int current_label) 
{
	if (x < 0 || x >= ROW || y < 0 || y >= COL || label[x][y] || !img[x][y])
		return; 

	// mark the current cell
	label[x][y] = current_label;

	// recursively mark the neighbors
	for (int grads = 0; grads < CONNECTIVITY; ++grads)
	{
		depth_first_search(x + dx[grads], y + dy[grads], current_label);
	}
}

int countBlobs() 
{
	int labels = 0;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (!label[i][j] && img[i][j])
			{
				//Skip the single pixel blobs
				//Search the neighborhood and if the current pixel is the only foreground pixel
				//then ignore it.
				bool bSinglePixel = true;
				for (int direction = 0; direction < CONNECTIVITY; ++direction)
				{
					int iRow = i + dx[direction];
					int iCol = j + dy[direction];

					if (iRow >= 0 && iRow < ROW && iCol >= 0 && iCol < COL && img[iRow][iCol])
						bSinglePixel = false;
				}
				if (bSinglePixel)
					continue;

				//Once we are done with labeling all the neighborhoods of one pixel
				//We go to the next pixel
				depth_first_search(i, j, ++labels);
			}
		}
	}
	
	return labels;
}

int main()
{
	int labels = countBlobs();

	std::cout << "Number of blobs counted:  " << labels << std::endl;

	std::cin.get();

	return 0;
}
