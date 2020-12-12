#include "funcHeader.h"

struct productStructure arr[MAXNUMBER] = {

	{"A1",10,20,10,2.15,"Oreo"},
	{"A2",20,20,10,2.25,"Lays"},
	{"A3",20,20,10,2.35,"Maynards"},
	{"A4",20,20,10,2.45,"Dairy Milk"},
	{"A5",20,20,10,2.55,"Coke"},
	{"A6",20,20,10,2.65,"Pepsi"},
	{"A7",20,20,10,2.75,"M&Ms"},
	{"A8",20,20,10,2.85,"Skittles"},
	{"A9",20,20,10,2.95,"Excel"}
};

struct paymentStructure payment;

void mainHandler(void) {

	printf("***Welcome to the Vending Machine Program***\n\n");

	int keepTrying = 1;

	do {
		menu();
		buttons();
		keyPress();

		printf("Hello welcome again. In order to exit, please press 0, any other number to buy another product: ");
		scanf("%d", &keepTrying);

		while (keepTrying != 0) {

			printf("Enter 0 to exit. Try again: ");
			scanf("%d%c", &keepTrying);
		}

	} while (keepTrying != 0);

	printf("\nThank you very much for your interest. Have a wonderful day.");
}

void menu(void) {

	printf("Menu:\n");
	printf("Slot-ID	Quantity	Min Quantity	Max Quantity	Price	Description\n");

	for (int i = 0; i < MAXNUMBER; i++) {

		printf("%s	%d		%d		%d		%.2lf	%s\n", arr[i].slotID, arr[i].quantity, arr[i].maxQuantity, arr[i].minQuantity, arr[i].price, arr[i].description);
	}
}

void buttons(void)
{
	printf("\nButtons: \n");
	printf("A	B	C	D	E\n");
	printf("1	2	3	4	5\n");
	printf("6	7	8	9	10\n");
	printf("Correct		Cancel\n");
	printf("ENTER		PAY\n");
}

void keyPress(void) {

	char keyClick = '\0', second = '\0';
	int keepTrying = 0;

	//LCD screen purposely turned off, once the user enters any key, it will direct them to follow a set of instructions in order to obtain their product
	printf("\nLet's begin by pressing (C)orrect, (P)ay or (E)nter buttons only: ");
	scanf("%c%c", &keyClick, &second);

	if (second != '\n') 
		trCharsInKeyPress(&keyClick, &second);

	while (!(keyClick == 67 || keyClick == 69 || keyClick == 80)) {

		printf("Please enter (C)orrect, (P)ay (E)nter buttons only: ");
		scanf("%c%c", &keyClick, &second);

		if (second != '\n')
			trCharsInKeyPress(&keyClick, &second);
	}

	paymentScreen();
	lcdScreen();
}

void trCharsInKeyPress(char* keyClickPtr, char* secondPtr) {

	while (*secondPtr != '\n') {

		printf("No trailing characters allowed. Press (C)orrect, (P)ay or (E)nter button on the keypad: ");
		scanf("%*c%c%c", keyClickPtr, secondPtr);
	}
}

void paymentScreen(void) {

	printf("\n		*** Payment Screen ***					\n");
	printf("Debit cards, Credit cards, Tap or NFC payments are allowed\n");
	printf("********************NO CASH ACCEPTED**********************\n\n");

}

void lcdScreen(void) {

	char first, second, third;

	printf("Begin with selecting a product of your choice, A + (1 to 9) keystrokes allowed: ");
	scanf("%c%c%c", &first, &second, &third);

	if (third != '\n')
		trCharsInSelection(&first, &second, &third);

	selection(&first, &second, &third);
	checkAndProceed(&first, &second);
}

void selection(char* firstPtr, char* secondPtr, char* thirdPtr) {

	//firstPtr, secondPtr, thirdPtr are a pointer pointing to first, second, third
	//add third pointer for 0 to 9, for 2 digit numbers, eg A10 and third condition similar to secind condition
	while (!(*firstPtr == 'A' && *secondPtr >= 49 && *secondPtr <= 57)) {

		printf("\nOnly products ranging from A1 to A9 are available. Please try again: ");
		scanf("%c%c%c", firstPtr, secondPtr, thirdPtr);

		if (*thirdPtr != '\n')
			trCharsInSelection(firstPtr, secondPtr, thirdPtr);
		//these three pointers are already pointing to a variable, so when we write the name of these pointers, it means we are passing the address that they are pointing to. &firstPtr means address of the pointer, firstPtr means address of the variable that they are pointing to.
	}

	while (*firstPtr == 'A' && !(*secondPtr >= 49 && *secondPtr <= 57)) {

		printf("Number entered is incorrect. Please enter a combination of A with 1 to 9 numbers: ");
		scanf("%c%c%c", firstPtr, secondPtr, thirdPtr);

		if (*thirdPtr != '\n')
			trCharsInSelection(firstPtr, secondPtr, thirdPtr);
	}

	while (*firstPtr != 'A' && *secondPtr >= 49 && *secondPtr <= 57) {

		printf("Alphabet entered is incorrect. Please enter a combination of A with 1 to 9 numbers: ");
		scanf("%c%c%c", firstPtr, secondPtr, thirdPtr);

		if (*thirdPtr != '\n')
			trCharsInSelection(firstPtr, secondPtr, thirdPtr);
	}
}

void trCharsInSelection(char* firstPtr, char* secondPtr, char* thirdPtr) {

	while (*thirdPtr != '\n') {

		printf("No trailing characters allowed. Press A + (1 to 9) button on the keypad: ");
		scanf("%*c%c%c%c", firstPtr, secondPtr, thirdPtr);
	}
	//here the three pointers are pointing to first, second & third variables from lcdScreen function, since they were passed the addresss of the previous pointers' variables, by passing just the names of firstPtr, secondPtr & thirdPtr. 
}


void checkAndProceed(char* firstPtr, char* secondPtr) {

	char cancelOrCorrect, second;

	printf("\nPress (C)ancel to cancel and exit or (c)orrect to change selection or any other character to pay: ");
	scanf("%c%c", &cancelOrCorrect, &second);

	while (second != '\n') {

		printf("No trailing characters allowed. Press (C)ancel, (c)orrect on the keypad: ");
		scanf("%*c%c%c", &cancelOrCorrect, &second);
	}

	if (cancelOrCorrect == 'C') {
		printf("\nThank you for your time. We hope to see you soon\n\n");
		exit(0);
		//exit will terminate the program
	}
	else if (cancelOrCorrect == 'c') {
		printf("\nYou have chosen to correct your selection. Please proceed.\n\n");
		lcdScreen();
	}
	else {
		int quantity, exitStatus = 0; 

			for (int i = 0; i < MAXNUMBER; i++) {

				if (*firstPtr == arr[i].slotID[0] && *secondPtr == arr[i].slotID[1]) {

					printf("\nHow much quantity of %s do you need: ", arr[i].description);
					scanf("%d", &quantity);

					while (quantity > arr[i].maxQuantity || quantity > arr[i].quantity) {

						printf("Max quantity of %s available in stock is %d. Please try again: ", arr[i].description, arr[i].quantity);
						scanf("%d", &quantity);
					}
					
					printf("\nGet ready for payment...\n");

					strcpy(payment.slotID, arr[i].slotID);
					payment.quantity = quantity;
					payment.price = arr[i].price;
					strcpy(payment.description, arr[i].description);

					paymentFunc();
					//loop thru slot id and find the slot id in the arr.slotID and pass this element to the structure in logic 3
					//go ahead with the payment process, call the get payment function.....


					/*arr[i].quantity -= quantity;
					if (arr[i].quantity < arr[i].minQuantity)
						arr[i].quantity = arr[i].maxQuantity;*/		//also update the current qty and if it drops to below min qty then top it up to max qty
				}
			}
	}
}

void paymentFunc(void) {

	double totalPrice = payment.price * payment.quantity;
	char first, second;

	printf("Total price: %.2lf", totalPrice);
	printf("\nEnter (P)ay to pay the price: ");
	scanf("%*c%c%c", &first, &second);

	if (second != '\n')
		trCharsinPaymentFunc(&first, &second);

	while (first != 'P') {

		printf("Trailing characters are not allowed, Enter (P)ay to pay the price: ");
		scanf("%*c%c%c", &first, &second);

		if (second != '\n')
			trCharsinPaymentFunc(&first, &second);
	}

	printf("Transaction successful. Thank you.\n\n");

//code a function that'll detect if a card/mobile etc payment methods are brought closer to the payment module
//Course of action if a payment is refused
}

void trCharsinPaymentFunc(char* firstPtr, char* secondPtr) {

	while (*secondPtr != '\n') {

		printf("Trailing characters are not allowed, Enter (P)ay to pay the price: ");
		scanf("%*c%c%c", firstPtr, secondPtr);
	}
}