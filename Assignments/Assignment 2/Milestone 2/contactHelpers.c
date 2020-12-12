/* -------------------------------------------
Name: Soham Thaker
Student number: 011-748-159
Email: sdthaker1@myseneca.ca
Section: NBB
Date: 09/11/2020
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS


//#include <ctype.h>
#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


//////////////////////////////////////////////////////////////////////
// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n');  // empty statement intentional
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// getInt: Empty function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int value;

	scanf(" %d%c", &value, &NL);

	while (NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &NL);
	}
	return value;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int recInt = getInt();

	while (recInt < min || recInt > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",
			min, max);
		recInt = getInt();
	}
	
	return recInt;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// yes: Empty function definition goes here:
int yes(void)
{
	char first = 'x' , second = 'x';
	
	scanf("%c%c", &first, &second);
	
	while ((first != 'Y' || first != 'y' || first != 'n'|| first != 'N') && (second != '\n'))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &first, &second);
	}

	return (first == 'y' || first == 'Y') ? 1 : 0; //check if you need the braces around char yes

	/*char yesno = '\0', remain = '\0';
	int validch = 2;

	do
	{
		scanf("%c%c",&yesno,&remain);

		if (yesno == 'Y' || yesno == 'y' && remain == '\n')
			validch = 1;
		else if (yesno == 'N' || yesno == 'n' && remain == '\n')
			validch = 0;
		else
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (validch == 2);

	return validch;*/
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// menu: Empty function definition goes here:
int menu(void)
{

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	printf("\n");

}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ContactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int check, a;

	do
	{
		check = menu();
		a = 0;

		switch (check)
		{
			case 0:
				printf("\nExit the program? (Y)es/(N)o: ");
				if (yes())
				{
					printf("\nContact Management System: terminated\n");
					a++;
					break;
				}
				else
				{
					printf("\n");
					break;
				}
			case 1:
				printf("\n<<< Feature 1 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 2:
				printf("\n<<< Feature 2 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 3:
				printf("\n<<< Feature 3 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 4:
				printf("\n<<< Feature 4 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 5:
				printf("\n<<< Feature 5 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 6:
				printf("\n<<< Feature 6 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
		}
	} while (a == 0);

}
//////////////////////////////////////////////////////////////////////