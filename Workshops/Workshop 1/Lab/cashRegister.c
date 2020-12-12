//==============================================
// Name:           Soham Thaker
// Student Number: 011-748-159
// Email:          sdthaker1@myseneca.ca
// Section:        NBB
// Workshop:       2 (in-lab)
//==============================================
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
int main()
{
    double amountDue, remaining, quarters = 0.25;
    int loonies = 1, looniesRequired, quartersRequired;

    printf("Please enter the amount to be paid: $");
    scanf("%lf", &amountDue);

    looniesRequired = amountDue / loonies; //8.68/1 = 8
    remaining = amountDue - looniesRequired; //8.68-8 = 0.68

    printf("Loonies required: %d, balance owing $%.2lf\n", looniesRequired, remaining); //8 , 0.68

    quartersRequired = remaining / quarters; //0.68/0.25 = 2/72 = 2
    remaining = remaining - (quarters * quartersRequired);

    printf("Quarters required: %d, balance owing $%.2lf\n", quartersRequired, remaining);

    return 0;
}



