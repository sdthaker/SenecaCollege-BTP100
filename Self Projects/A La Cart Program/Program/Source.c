#include <stdio.h>
float totalpeople(float* child, float* adult, float* senior);
float coverprice(float child, float adult, float senior);
float event(float totalp, char* morenum);
float discount(float totalp, float totalticketprice);
float snackc();
int valetparking(char* morenum);
void printreceipt(float covercharges, float ticketcharges, float snackcharges, float valetcharges, float discountsapplied);
void totalcost(float covercharges, float ticketcharges, float discountsapplied, float snackcharges, float valetcharges);
char more(void);
char torm(void);
int trueorfalse();

void main()
{
	float child = 0, adult = 0, senior = 0;
	char c = '\0';
	char* morenum = &c;
	float totalp = totalpeople(&child, &adult, &senior);
	float covercharges = coverprice(child, adult, senior);
	float ticketcharges = event(totalp, &morenum);
	float discountsapplied = discount(totalp, ticketcharges);
	float snackcharges = snackc();
	float valetcharges = valetparking(&morenum);
	printreceipt(covercharges, ticketcharges, snackcharges, valetcharges, discountsapplied);
	totalcost(covercharges, ticketcharges, discountsapplied, snackcharges, valetcharges);
}

float totalpeople(float* child, float* adult, float* senior)
{
	printf("enter total number of child: ");
	scanf("%f", child);

	printf("enter total number of adult: ");
	scanf("%f", adult);

	printf("enter total number of senior: ");
	scanf("%f", senior);

	return (*child + *adult + *senior);
}

float coverprice(float child, float adult, float senior)
{
	float ch = 0.50, ad = 5.50, sen = 1.25;
	float total;

	return total = (child * ch) + (adult * ad) + (senior * sen);
}

float event(float totalp, char* morenum)
{
	float musicalm = 88, musicale = 175, theatrem = 78, theatree = 165;

	printf("press 'm' for afternoon and 'e' for evening: ");
	*morenum = more();

	printf("press 't' for theatre and 'm' for musical: ");
	char tormnum = torm();

	if (tormnum == 't' && *morenum == 'm')
	{
		return theatrem * totalp;
	}
	else if (tormnum == 't' && *morenum == 'e')
	{
		return theatree * totalp;
	}
	else if (tormnum == 'm' && *morenum == 'm')
	{
		return musicalm * totalp;
	}
	else if (tormnum == 'm' && *morenum == 'e')
	{
		return musicale * totalp;
	}
}

float discount(float totalp, float totalticketprice)
{
	float totaldiscount = 0.05;

	if (totalp <= 1)
	{
		return totalp * totalticketprice * (totaldiscount - 0.05);
	}
	else if (totalp == 2)
	{
		return totalp * totalticketprice * totaldiscount;
	}
	else if (totalp == 3)
	{
		return totalp * totalticketprice * (totaldiscount + 0.05);
	}
	else if (totalp == 4)
	{
		return totalp * totalticketprice * (totaldiscount + 0.10);
	}
	else
	{
		return totalp * totalticketprice * (totaldiscount + 0.15);
	}
}

float snackc()
{
	float snacknonalcoholic = 3.00, snackalcoholic = 7.75, snackmisccandy = 2.50;
	float alcoholicamount, nonalcoholicamount, miscamount;

	printf("enter alcoholic snack quantity: ");
	scanf("%f", &alcoholicamount);

	printf("enter non alcoholic snack quantity: ");
	scanf("%f", &nonalcoholicamount);

	printf("enter miscallenous snack quantity: ");
	scanf("%f", &miscamount);

	return ((snacknonalcoholic * alcoholicamount) + (snackalcoholic * nonalcoholicamount) + (snackmisccandy * miscamount));
}

int valetparking(char* morenum)
{
	float valetparkingmatineestandard = 15, valetparkingmatineevip = 25, valetparkingeveningstandard = 20, valetparkingeveningvip = 30;
	if (*morenum == 'm')
	{
		while (getchar() != '\n');
		char c;

		printf("do you have a car? press 'y' or 'y' for yes, any character for no: ");
		if (trueorfalse())
		{
			printf("press 's' for standard valet or 'v' for vip valet: ");
			scanf("%c%*c", &c);

			if (c == 's')
			{
				printf("do you want to tip the driver? press 'y' or 'y' for yes, any character for no: ");

				if (trueorfalse())
				{
					return valetparkingmatineestandard + 5;
				}
				else
				{
					return valetparkingmatineestandard;
				}
			}
			else if (c == 'v')
			{
				printf("do you want to tip the driver? press 'y' or 'y' for yes, any charactrer for no: ");

				if (trueorfalse())
				{
					return valetparkingmatineevip + 5;
				}
				else
				{
					return valetparkingmatineevip;
				}
			}
		}
		else
		{
			return 0;
		}
	}

	else if (*morenum == 'e')
	{
		while (getchar() != '\n');
		char c;

		printf("do you have a car? press 'y' or 'y' for yes, any character for no: ");
		if (trueorfalse())
		{
			printf("press 's' for standard valet or 'v' for vip valet: ");
			scanf("%c%*c", &c);

			if (c == 's')
			{
				printf("do you want to tip the driver? press 'y' or 'y' for yes, any character for no: ");

				if (trueorfalse())
				{
					return valetparkingeveningstandard + 5;
				}
				else
				{
					return valetparkingeveningstandard;
				}
			}
			else if (c == 'v')
			{
				printf("do you want to tip the driver? press 'y' or 'y' for yes, any charactrer for no: ");

				if (trueorfalse())
				{
					return valetparkingeveningvip + 5;
				}
				else
				{
					return valetparkingeveningvip;
				}
			}
		}
		else
		{
			return 0;
		}
	}
}

void printreceipt(float covercharges, float ticketcharges, float snackcharges, float valetcharges, float discountsapplied)
{
	printf("\nreceipt of all charges: \n");
	printf("cover charges     ticket charges     snack charges     valet charges     discounts applied\n");
	printf("%-18.2f%-18.2f %-18.2f%-18.2f%-17.2f\n", covercharges, ticketcharges, snackcharges, valetcharges, discountsapplied);
}

void totalcost(float covercharges, float ticketcharges, float discountsapplied, float snackcharges, float valetcharges)
{
	float totalcost = ((covercharges + ticketcharges + snackcharges + valetcharges) - discountsapplied);
	printf("\ntotal cost: %.2f\n", totalcost);
}

char more(void)
{
	while (getchar() != '\n');
	char c;
	scanf("%c", &c);

	if (c == 'm')
	{
		return 'm';
	}
	else if (c == 'e')
	{
		return 'e';
	}
}

char torm(void)
{
	while (getchar() != '\n');
	char c;
	scanf("%c", &c);

	if (c == 't')
	{
		return 't';
	}
	else if (c == 'm')
	{
		return 'm';
	}
}

int trueorfalse()
{
	char truefalse;
	scanf("%c%*c", &truefalse);

	return (truefalse == 'y' || truefalse == 'y') ? 1 : 0;
}
