//==============================================
// Name:           Soham Thaker
// Student Number: 001-748-159
// Email:          sdthaker1@myseneca.ca
///Section:        NBB
///Workshop:       3 (at-home)
//==============================================


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Put your code below:
#define NUMS 4

int main()
{
	printf("---=== IPC Temperature Analyzer ===---");

	int high, low, compareLow = 0, compareHigh = 0, compareHighDay = 0, compareLowDay = 0,i;
	double avgHigh = 0.0, avgLow = 0.0, overall = 0.0;

	for (i = 1; i <= NUMS; i++)
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

		if (high > compareHigh)
		{
			compareHigh = high;
			compareHighDay = i;
		}

		if (low < compareLow)
		{
			compareLow = low;
			compareLowDay = i;
		}

		avgHigh += high;
		avgLow += low;
	}

	avgHigh = avgHigh / NUMS;
	avgLow = avgLow / NUMS;
	overall = (avgHigh + avgLow) / 2;

	printf("\nThe average (mean) LOW temperature was: %.2lf\n", avgLow);
	printf("The average (mean) HIGH temperature was: %.2lf\n", avgHigh);
	printf("The average (mean) temperature was: %.2lf\n", overall);
	printf("The highest temperature was %d, on day %d\n", compareHigh, compareHighDay);
	printf("The lowest temperature was %d, on day %d\n", compareLow, compareLowDay);

	return 0;
}