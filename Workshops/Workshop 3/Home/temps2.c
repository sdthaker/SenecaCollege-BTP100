//==============================================
// Name:           Soham Thaker
// Student Number: 011748159
//// Email:          sdthaker1@myseneca.ca
//// Section:        NBB
//// Workshop:       4 (in-lab)
////==============================================

#define _CRT_SECURE_NO_WARNINGS
//
//// Put your code below:
#include <stdio.h>
#define NUMS 10

int main()
{
	int days, daysNum, a = 0, b = 0, compareHigh = 0, compareLow = 0, compareHighDay, compareLowDay,i,j,k;
	int highArr[NUMS], lowArr[NUMS];

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);

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
		printf("Day %d - High: ", i+1);
		scanf("%d", &highArr[i]);

		printf("Day %d - Low: ", i+1);
		scanf("%d", &lowArr[i]);

		if (highArr[i] > compareHigh)
		{
			compareHigh = highArr[i];
			compareHighDay = i+1;
		}

		if (lowArr[i] < compareLow)
		{
			compareLow = lowArr[i];
			compareLowDay = i+1;
		}
	}

	printf("\nDay  Hi  Low\n");
	for (j = 0; j < days; j++)
	{
		printf("%d    %d    %d\n", j+1, highArr[j], lowArr[j]);
	}

	printf("\nThe highest temperature was %d, on day %d\n",compareHigh,compareHighDay);
	printf("The lowest temperature was %d, on day %d\n",compareLow,compareLowDay);
	
	do
	{
		double avgHigh = 0.0, avgLow = 0.0, overall = 0.0;

		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &daysNum);
		 
		if (daysNum >= 1 && daysNum <= days)
		{
			for (k = 0; k < daysNum; k++)
			{
				avgHigh += highArr[k];
				avgLow += lowArr[k];
			}
			avgHigh = avgHigh / daysNum;
			avgLow = avgLow / daysNum;

			overall = (avgHigh + avgLow) / 2;

			printf("\nThe average temperature up to day %d is: %.2lf\n",daysNum, overall);
		}
		
		else if(daysNum	 == 0 || daysNum > days)
		{
			do
			{
				a = 1;
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
				scanf("%d", &daysNum);

				if (daysNum >= 1 && daysNum <= days)
				{
					for (k = 0; k < daysNum; k++)
					{
						avgHigh += highArr[k];
						avgLow += lowArr[k];
					}
					avgHigh = avgHigh / daysNum;
					avgLow = avgLow / daysNum;

					overall = (avgHigh + avgLow) / 2;

					printf("\nThe average temperature up to day %d is: %.2lf\n", daysNum, overall);
					a++;
				}

			} while (a != 2);
		}

		else if (daysNum < 0)
		{
			b--;
		}

	} while (b == 0);

	printf("\nGoodbye!");

	return 0;
}