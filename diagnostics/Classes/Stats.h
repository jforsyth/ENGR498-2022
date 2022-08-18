#pragma once

#define NULL 0

class Stats
{

private:
	static Stats* instance;

	Stats();
	~Stats();

public:
	static Stats* getInstance();

	float calculateMean(int* data, int len);
	float calculateStandardDeviation(int* data, int len);

};

