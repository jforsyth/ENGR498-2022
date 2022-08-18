#include <iostream>
#include "Stats.h"
#include "Helper.h"


int main()
{

	int* data = NULL;
	int length = randomPopulate(data);

	std::cout << "Data is : ";
	for (int i = 0; i < length; i++)
	{
		std::cout << data[i] << std::endl;
	}

	Stats* statsPackage = Stats::getInstance();

	float mean = statsPackage->calculateMean(data, length);
	float stdDev = statsPackage->calculateStandardDeviation(data, length);

	std::cout << "Mean is " << mean << std::endl;
	std::cout << "Standard Deviation is " << stdDev << std::endl;
}