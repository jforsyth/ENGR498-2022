#include "Stats.h"
Stats* Stats::instance = NULL;	

Stats::Stats()
{

}

Stats* Stats::getInstance()
{
	if (instance == NULL)
	{
		instance = new Stats();
	}
	else
	{
		return instance;
	}
}

float Stats::calculateMean(int* data, int len)
{

	//YOUR CODE HERE

	return 0;
}

float Stats::calculateStandardDeviation(int* data, int len)
{
	//YOUR CODE HERE

	return 0;
}