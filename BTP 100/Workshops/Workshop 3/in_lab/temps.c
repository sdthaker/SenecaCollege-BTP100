//==============================================
// Name:           Soham Thaker
// Student Number: 001-748-159
// Email:          sdthaker1@myseneca.ca
// Section:        NBB
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Put your code below:
#define NUMS 3

int main()
{
	printf("---=== IPC Temperature Analyzer ===---");

	int high, low,i;

	for (i = 1; i <= NUMS /*&& j!= 1*/; i++)
	{
		int j = 0;
		do
		{
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &high);

			printf("\n");

			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);

			if (high > low && high < 41 && low > -41)
			{ 
				j++;
			}
			else
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}
		} while (j != 1);
	}
	
	return 0;
}