/* -------------------------------------------
Name: Soham Thaker
Student number: 011-748-159
Email: sdthaker1@myseneca.ca
Section: NBB
Date: 09/11/2020
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

//#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXCONTACTS 5
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 4 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-4 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


//////////////////////////////////////////////////////////////////////
// Clear the standard input buffer
void clearKeyboard(void)
{
	while ((getchar()) != '\n');  // empty statement intentional
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// pause: Empty function definition goes here:
void pause(void)
{
	printf("\n(Press Enter to Continue)\n");
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

	while (NL != '\n') {

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

	while (recInt < min || recInt > max) {

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
	char first = 'x', second = 'x';

	scanf(" %c%c", &first, &second);

	while ((first != 'Y' && first != 'y' && first != 'n' && first != 'N') || (second != '\n')) {

		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &first, &second);
	}

	return (first == 'y' || first == 'Y') ? 1 : 0;
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
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);

}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ContactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int check, a;

	struct Contact contactArr[MAXCONTACTS] =
	{
	  {
		{ "Rick", {'\0'}, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" }
	  },

	  {
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" }
	  },

	  {
		{ "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" }
	  },

	  {
		{ "Sasha", {'\0'}, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" }
	  },
	};

	do {
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
			displayContacts(contactArr, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contactArr, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contactArr, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contactArr, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contactArr, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contactArr, MAXCONTACTS);
			pause();
			break;
		}
	} while (a == 0);

}
//////////////////////////////////////////////////////////////////////

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+


// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[]) 
{
	scanf("%s", phoneNum);
	clearKeyboard();
	int i, num = 0;

	while (strlen(phoneNum) < 10 || strlen(phoneNum) > 10) {

		printf("Enter a 10-digit phone number: ");
		scanf("%s", phoneNum);
		clearKeyboard();
	}

	while (num != 10) {

		num = 0;

		for (i = 0; i < strlen(phoneNum); i++) {

			if (phoneNum[i] >= 48 && phoneNum[i] <= 57)
				num++;
		}

		if (num < 10) {

			printf("Enter a 10-digit phone number: ");
			scanf("%s", phoneNum);
			clearKeyboard();
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, j=0, k=0;
	for (i = 0; i < size; i++) {

		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {

			k = i;
		}
		else {

			j++;
		}
	}
	return (j == 5) ? -1 : k;
}
	

// displayContactHeader:
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+");
}

// displayContactFooter:
void displayContactFooter(int count) 
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact) 
{
	printf("\n %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) > 0)
		printf("%s ", contact->name.middleInitial);
	printf("%s\n", contact->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s", contact->address.city,contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) 
{
	displayContactHeader();
	int i,j=0;
	for (i = 0; i < size; i++) {

		if (strlen(contacts[i].numbers.cell) > 0) {

			displayContact(&contacts[i]);
			j++;
		}
	}
	displayContactFooter(j);
}

// addContact:
void addContact(struct Contact contacts[], int size) 
{
	int index;
	char cell[11] = { '\0' };
	
	index = findContactIndex(contacts, size, cell);

	if (index == -1) {

		printf("\n*** ERROR: The contact list is full! ***\n");
	}
	else {

		printf("\n");
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size) 
{
	char cell[11] = {'\0'};
	int index;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);

	index = findContactIndex(contacts, size, cell);

	if (index == -1) {

		printf("*** Contact NOT FOUND ***\n");
	}
	else {

		printf("\nContact found:");
		displayContact(&contacts[index]);

		printf("\n\nDo you want to update the name? (y or n): ");
		if (yes())
			getName(&contacts[index].name);

		printf("Do you want to update the address? (y or n): ");
		if (yes())
			getAddress(&contacts[index].address);

		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
			getNumbers(&contacts[index].numbers);

		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) 
{
	char cell[11] = {'\0'};
	int index;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);

	index = findContactIndex(contacts, size, cell);

	if (index == -1) {

		printf("*** Contact NOT FOUND ***\n");
	}
	else {

		printf("\nContact found:");
		displayContact(&contacts[index]);

		printf("\n\nCONFIRM: Delete this contact? (y or n): ");
		if (yes()) {

			contacts[index].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	int index;
	char cell[11] = { '\0' };

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);

	index = findContactIndex(contacts, size, cell);

	if (index >= 0) {

		displayContact(&contacts[index]);
		printf("\n");
	}
	else {

		printf("*** Contact NOT FOUND ***\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) 
{
	int i, j;
	struct Contact temp;

	for(i = 0; i < size-1; i++) {

		for (j = i + 1; j < size; j++) {

			if (strlen(contact[i].numbers.cell) != 0 && strlen(contact[j].numbers.cell) != 0 && strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {

				temp = contact[i];
				contact[i] = contact[j];
				contact[j] = temp;
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n");
}