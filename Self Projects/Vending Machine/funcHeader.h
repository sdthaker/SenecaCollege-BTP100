#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMBER 9


void mainHandler(void);
void menu(void);
void buttons(void);
void keyPress(void);
void paymentScreen(void);
void selection(char* firstPtr, char* secondPtr, char* thirdPtr);
void trCharsInKeyPress(char* keyClickPtr, char* secondPtr);
void trCharsInSelection(char* firstPtr, char* secondPtr, char* thirdPtr);
void checkAndProceed(char* firstPtr, char* secondPtr);
void lcdScreen(void);
void paymentFunc(void);
void trCharsinPaymentFunc(char* firstPtr, char* secondPtr);

struct productStructure {

	char slotID[2];
	int quantity, maxQuantity, minQuantity;
	double price;
	char description[10];
};

struct paymentStructure {

	char slotID[2];
	int quantity;
	double price;
	char description[10];
};