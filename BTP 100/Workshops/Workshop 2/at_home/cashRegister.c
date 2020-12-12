#include<stdio.h>

int main()
{
	double amountDue, GST;
	int remaining, loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue);

	printf("GST: 1.13\n");

	GST = amountDue * 0.13 + 0.005;
	amountDue = amountDue + GST;

	printf("Balance owing: $%.2lf\n", amountDue);

	remaining = amountDue * 100;

	loonies = remaining / 100;
	remaining = remaining % 100;

	printf("Loonies required: %d, balance owing $%1.2lf\n", loonies, (double)remaining / 100);

	quarters = remaining / 25;
	remaining = remaining % 25;

	printf("Quarters required: %d, balance owing $%1.2lf\n", quarters, (double)remaining / 100);

	dimes = remaining / 10;
	remaining = remaining % 10;

	printf("Dimes required: %d, balance owing $%1.2lf\n", dimes, (double)remaining / 100);

	nickels = remaining / 5;
	remaining = remaining % 5;

	printf("Nickels required: %d, balance owing $%1.2lf\n", nickels, (double)remaining / 100);

	pennies = remaining / 1;
	remaining = remaining % 1;

	printf("Pennies required: %d, balance owing $%1.2lf\n", pennies, (double)remaining / 100);

	return 0;
}
