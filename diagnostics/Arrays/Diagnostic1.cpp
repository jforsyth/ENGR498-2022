#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int randomPopulate(int*& data)
{
	//provide a random seed
	srand(time(NULL));

	//generate random length betwee 1 - 100
	int length = (rand() % 100) + 1;

	//create a new array of that length
	data = new int[length];

	//populate array with random values between 1 and 1000
	int* ptr = data;
	for (int i = 0; i < length; i++)
	{
		int value = (rand() % 1000) + 1;
		*ptr = value;
		ptr++;
	}

	return length;
}

int main()
{

	/**
	*
	* Step 1: Generate an integer array of random length and contents
	*
	*/
	int* data = NULL;
	int length = randomPopulate(data);

	std::cout << "Data is : ";
	for (int i = 0; i < length; i++)
	{
		std::cout << data[i] << std::endl;
	}


	/**
	*
	* Step 2: Calculate the minimum, maximum, and average of the array
	*/

	int min = -1;
	int max = -1;
	int average = -1;

	//YOUR CODE GOES HERE//

	cout << "Minimum value is: " << min << endl;
	cout << "Maximum value is: " << max << endl;
	cout << "Average value is: " << average << endl;


	return 0;

}