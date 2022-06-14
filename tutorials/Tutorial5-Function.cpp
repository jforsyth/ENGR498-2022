#include <iostream>
using namespace std;

/**
	Write two functions. The first, should take two integers and return their sum as the result.

	The second should take two integer arrays and perform the dot product opreation. Thus if there
	are two arrays (a and b) then the result should be a[0]*b[0] + a[1]*b[1] + a[2]*b[2] +....

*/

int sumFunction(int a, int b)
{
	//Your code here
	
	return 0;
}

/**
@param a: an array of integers
@param b: an array of integers
@param len: the length of arrays a or b.

@return: the dot product of arrays a and b.
*/
int dotProduct(int* a, int* b, int len)
{
	int sum = 0;
	
	//Your code here

	return sum;
}

int main()
{

	//sum the numbers 10 and 3. The result should be 13.
	int sum = sumFunction(10, 3);

	//perform the dot product on these arrays. The result should be 85.
	int a[] = { 0,1,2,3,4,5 };
	int b[] = { 2,3,4,5,6,7 };

	int dot = dotProduct(a, b, 6);


	return 0;
}