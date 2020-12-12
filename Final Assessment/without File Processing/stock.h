#pragma once

#include <stdio.h>
#include <string.h>

#define  _CRT_SECURE_NO_WARNINGS

#define NUM_CATS 7
#define MAX_ITEMS_IN_SALE 100

struct Record {

	int quantity;
	int category;
	double price;
	int productID;
};

struct StockRecord {

	struct Record records;

	char name[26];
	double soldByWeight;
};

struct SalesRecord {

	int productID;
	int quantity;
	char productName[26];
};

struct SaleStock {

	char name[26], strCategory[15];
	int qty;
};

struct SalesProduct {

	char productName[26];
	int qty;
};

int readStockItems(struct StockRecord storeStock[], int MAX_STOCK_ENTRIES, int STOCK_FROM_STDIN);
void soldByFunc(struct StockRecord* storeStock, char* buf);
char* catString(int category);
void centreText(int num, char str, char str1[]);
int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord saleItems[]);
void readSaleData(int* numProdID, int* qty, int* ptrSold, int* keepTrying, struct SaleStock saleStock[], struct StockRecord storeStock[], struct SalesRecord saleItems[]);
void printStockReport(struct StockRecord storeStock[], int numStockItems);
double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems);
void getTopSellers(struct StockRecord storeStock[], int numStockItems, struct SalesRecord topSellers[], int num, int loopVar);
void printTopSellers(struct StockRecord storeStock[], struct SalesRecord topSellers[], int num, int loopVar);
void readInput(char buf[], int num);

//0 is soldByNumber purchased, whereas 1 is soldByWeight
//category is the range from 1 to 7
//ID increases one by one until 0 is entered, for the total number of products entered

//category is an array of 7 categories, hard coded and the products are assigned to each category with the help of number 1 to 7