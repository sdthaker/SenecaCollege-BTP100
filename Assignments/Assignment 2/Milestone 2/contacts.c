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

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
///////////////////////////////////////////////////////////////////////////////////
void getName(struct Name* pName)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", pName->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes()) 
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", pName->middleInitial);
    }

    clearKeyboard();
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", pName->lastName);
}
///////////////////////////////////////////////////////////////////////////////////


// getAddress:
///////////////////////////////////////////////////////////////////////////////////
void getAddress(struct Address* pAddress)
{
    printf("Please enter the contact's street number: ");
    pAddress->streetNumber = getInt();
    
    if (pAddress->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        pAddress->streetNumber = getInt();
    }
   
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", pAddress->street);

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes())       
    {
        printf("Please enter the contact's apartment number: ");
        pAddress->apartmentNumber = getInt();

        if (pAddress->apartmentNumber < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            pAddress->apartmentNumber = getInt();
        }
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", pAddress->postalCode);                

    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", pAddress->city);
}
///////////////////////////////////////////////////////////////////////////////////


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
///////////////////////////////////////////////////////////////////////////////////
void getNumbers(struct Numbers* pNumbers)
{

    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]%*c", pNumbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes())               
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", pNumbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", pNumbers->business);
    }
}
///////////////////////////////////////////////////////////////////////////////////


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
///////////////////////////////////////////////////////////////////////////////////
void getContact(struct Contact* pContact)
{
    getName(&pContact->name);
    getAddress(&pContact->address);
    getNumbers(&pContact->numbers);
}