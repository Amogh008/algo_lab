#include <stdio.h>
#define SIZE 10000

int main()
{
	int arr[SIZE + 1];
	int i,j;
	arr[1] = 0;

	for (i = 1; i <= SIZE; i++)
	{
		arr[i] = 1;
	}

	for (i = 2; i <= SIZE; i++)
	{
		if(arr[i])
		{
			for (j = i*i; j <= SIZE; j = j + i)
			{
				arr[j] = 0;
			}
		}
	}
	
	//printing the result
	for (i = 1; i <= SIZE; i++)
	{
		if(arr[i] == 1)
			printf("%d is a prime number\n", i);
	}
}
