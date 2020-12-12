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
#define MAXCONTACTS 5
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
///////////////////////////////////////////////////////////////////////////////////
void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf(" %30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes()) {

        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }
    else {

        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}
///////////////////////////////////////////////////////////////////////////////////


// getAddress:
///////////////////////////////////////////////////////////////////////////////////
void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();

    if (address->streetNumber < 0) {

        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes())  {

        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();

        if (address->apartmentNumber < 0) {

            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else {

        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);

    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}
///////////////////////////////////////////////////////////////////////////////////


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
///////////////////////////////////////////////////////////////////////////////////
void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");

    if (yes()) {

        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else {

        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    if (yes()) {

        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {

        numbers->business[0] = '\0';
    }
}
///////////////////////////////////////////////////////////////////////////////////

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
///////////////////////////////////////////////////////////////////////////////////
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}