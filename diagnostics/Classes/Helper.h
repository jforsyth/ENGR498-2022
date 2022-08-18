#pragma once
#include <random>
#include <time.h>

int randomPopulate(int*& data)
{
	//provide a random seed
	srand(time(NULL));

	//generate random length betwee 1 - 100
	int length = (rand() % 100) + 1;

	//create a new array of that length
	data = new int[length];

	int* ptr = data;
	for (int i = 0; i < length; i++)
	{
		int value = (rand() % 1000) + 1;
		*ptr = value;
		ptr++;
	}

	return length;
}
