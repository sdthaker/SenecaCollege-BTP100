//==============================================
// Name:           Soham Thaker
// Student Number: 011748159
// Email:          sdthaker1@myseneca.ca
// Section:        NBB
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 10

int main()
{
	int days, a = 0, highArr[NUMS], lowArr[NUMS],i,j;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

		printf("Please enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d",&days);

		if (days < 3 || days >10)
		{
			do
			{
				printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
				scanf("%d", &days);

				if (days >= 3 && days <= 10)
				{
					a++;
				}

			} while (a != 1);
		}

		printf("\n");

	for (i = 0; i < days; i++)
	{
		printf("Day %d - High: ",i+1);
		scanf("%d", &highArr[i]);

		printf("Day %d - Low: ", i+1);
		scanf("%d", &lowArr[i]);

	}

	printf("\nDay  Hi  Low\n");
	for (j = 0; j < days; j++)
	{
		printf("%d    %d    %d\n", j+1,highArr[j],lowArr[j]);
	}

	return 0;
}
