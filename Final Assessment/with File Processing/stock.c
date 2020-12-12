/* 
Student Name: Soham Thaker
Student ID: 011-748-159
Seneca Email: sdthaker1@myseneca.ca

Student Name: Yousef Majidinejad
Student ID: 101-306-207
Seneca Email: ymajidinejad@myseneca.ca

Project includes file processing.
*/

#include "stock.h"

int soldItems = 0, arr[MAX_ITEMS_IN_SALE], numStkItem;
struct SaleStock saleStock[MAX_ITEMS_IN_SALE] = { 0 };

void getInput(char readInput[], int num, FILE* fp) {

	if (fp != NULL) {
		fgets(readInput, num, fp);
		readInput[strlen(readInput) - 1] = '\0';
	}
	else {
		fgets(readInput, num, stdin);
		readInput[strlen(readInput) - 1] = '\0';
	}
}

int readStockItems(struct StockRecord storeStock[], int MAX_STOCK_ENTRIES, int STOCK_FROM_STDIN) {

	FILE* fp = NULL;
	fp = fopen("data.txt", "r");
	
	int productID = 0, i = 0, blnContinue = 1;
	char readInput[2048] = { '\0' };

	do {
		
		getInput(readInput, 2048, fp);

		blnContinue = strcmp(readInput, "0") != 0 ? 1 : 0;

		if (blnContinue) {

			sscanf(readInput, "%d,%d,%lf,%lf,%25[^\n]", &storeStock[i].records.soldBy, &storeStock[i].records.category, &storeStock[i].records.price, &storeStock[i].quantity, storeStock[i].name);

			while (storeStock->records.category < 1 || storeStock->records.category > 7) {

				getInput(readInput, 2048, fp);

				sscanf(readInput, "%d,%lf,%lf,%25[^\n]", &storeStock[i].records.category, &storeStock[i].records.price, &storeStock[i].quantity, storeStock[i].name);
			}

			if (storeStock[i].quantity != 0 && storeStock[i].quantity != 1) {
				
				soldByFunc(&storeStock[i], readInput, fp);
			}

			storeStock[i].records.productID = i + 1;

			i++;
			productID++;
		}

	} while (blnContinue == 1);

	fclose(fp);
	return productID;
}

void soldByFunc(struct StockRecord* storeStock, char* readInput, FILE* fp) {

	int soldBy;

	while (storeStock->quantity != 0 && storeStock->quantity != 1) {

		getInput(readInput, 2048, fp);

		sscanf(readInput, "%d,%25[^\n]", &soldBy, storeStock->name);

		storeStock->quantity = soldBy;
	}
}

char* catString(int category) {

	char* str[15] = { '\0' };

	switch (category) {

	case 1:
		*str = "produce";
		break;
	case 2:
		*str = "bakery";
		break;
	case 3:
		*str = "meat";
		break;
	case 4:
		*str = "dairy";
		break;
	case 5:
		*str = "baking";
		break;
	case 6:
		*str = "house wares";
		break;
	case 7:
		*str = "miscellaneous";
		break;
	}
	return *str;
}

void centreText(int num, char str, char str1[]) {

	int size = num - strlen(str1);

	if (str1[0] != '\0') {

		if (size % 2 == 0) {

			for (int i = 1; i <= num; i++) {

				printf("%c", str);
				if (i == size / 2) {

					printf("%s", str1);
					i += strlen(str1);
				}
			}
		}
		else {
			for (int i = 1; i <= num; i++) {
				
				printf("%c", str);
				if ((i == (size / 2) + 1)) {

					printf("%s", str1);
					i += strlen(str1);
				}
			}
		}
	}
	else {

		for (int i = 0; i < num; i++) {
			printf("%c", '=');
		}
	}
}

void printStockReport(struct StockRecord storeStock[], int numStockItems) {

	char str[15] = { '\0' };
	int qty = 0;

	printf("%4s%31s%16s%8s%9s\n", "ID", "Product", "Category", "Price", "Quantity");

	for (int i = 0; i < numStockItems; i++) {

		strcpy(str, catString(storeStock[i].records.category));

		if (storeStock[i].records.soldBy < 0)
			qty = 0;
		else
			qty = storeStock[i].records.soldBy;

		printf("%4d%31s%16s%8.2lf%9d\n", storeStock[i].records.productID, storeStock[i].name, str, storeStock[i].records.price, qty);
	}
}

int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord saleItems[]) {
	
	int soldItem = 0, numProdID = 0, qty = 0, keepTrying = 0, *ptrSold = &soldItem;
	char readInput[2048] = { '\0' };
	FILE* fp = NULL;

	do {
		keepTrying = 0;
		printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
 		getInput(readInput, 2048, fp);

		sscanf(readInput, "%d,%d", &numProdID, &qty);

		if (numProdID > 0) {

			for (int j = 0; j < numStockItems && keepTrying == 0; j++) {

				if ((numProdID >= 1 && numProdID <= numStockItems) && (qty >= 0.10 && qty <= 100)) {

					if (numProdID == storeStock[j].records.productID) {

						readSaleData(&numProdID, &qty, ptrSold, &keepTrying, saleStock, storeStock, saleItems);
					}
				}

				else {

					if (numProdID < 1 || numProdID > numStockItems) {

						printf("Invalid Product - Enter a number between 0 and %d: ", numStockItems);

						getInput(readInput, 2048, fp);

						sscanf(readInput, "%d,%d", &numProdID, &qty);

						if (qty < 0.10 || qty > 100) {

							printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");

							getInput(readInput, 2048, fp);
							sscanf(readInput, "%d,%d", &numProdID, &qty);

							do {

								if (numProdID == storeStock[j].records.productID) {

									readSaleData(&numProdID, &qty, ptrSold, &keepTrying, saleStock, storeStock, saleItems);
								}
								j++;

							} while (keepTrying == 0);
						}
					}
				}
			}
		}
		soldItems += *ptrSold;
	} while (numProdID > 0);
	
	return numProdID == 0 && *ptrSold == 0 ? 0 : *ptrSold;
}

void readSaleData(int* numProdID, int* qty, int* ptrSold, int* keepTrying, struct SaleStock saleStock[], struct StockRecord storeStock[], struct SalesRecord saleItems[]) {

	saleItems[*numProdID - 1].productID = *numProdID;
	saleItems[*numProdID - 1].quantity = *qty;

	storeStock[*numProdID - 1].records.soldBy -= *qty;

	*ptrSold += 1;
	*keepTrying += 1;

	strcpy(saleStock[*numProdID - 1].name, storeStock[*numProdID - 1].name);

	if (storeStock[*numProdID - 1].records.soldBy < 0) {
		saleStock[*numProdID - 1].qty = storeStock[*numProdID - 1].records.soldBy + *qty;
	}
	else {
		saleStock[*numProdID - 1].qty = *qty;
	}
	strcpy(saleStock[*numProdID - 1].strCategory, catString(storeStock[*numProdID - 1].records.category));
}

double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems) {

	int check = 0;
	
	printf("\n");
	centreText(64, '*', " Seneca Groceries ");
	printf("\n");
	centreText(64, '=', "");
	printf("\n");

	double totalPrice = 0.00, tax = 0.00, totalPricePlusTax = 0.00;

	for (int i = 0; i < soldItems; i++) {

		check = 0;

		if (saleItems[i].productID != 0)
		{
			if (arr[i] == saleItems[i].productID) {
				check = 1;
			}

			float total = 0.00;

			if (check == 0) {

				if (storeStock[saleItems[i].productID - 1].records.soldBy < 0)
				{
					int qty = saleItems[i].quantity + storeStock[saleItems[i].productID - 1].records.soldBy;
					total = storeStock[saleItems[i].productID - 1].records.price * qty;
				}
				else {
					total = storeStock[saleItems[i].productID - 1].records.price * saleItems[i].quantity;
				}

				totalPrice += total;

				if (storeStock[saleItems[i].productID - 1].records.category == 6 || storeStock[saleItems[i].productID - 1].records.category == 7) {

					tax = total * 0.13;
				}

				printf("%30s%9.2lf%8.2lf\n", storeStock[saleItems[i].productID - 1].name, storeStock[saleItems[i].productID - 1].records.price, total);

				arr[i] = saleItems[i].productID;
			}
		}
	}

	printf("Purchase Total%33.2lf\n", totalPrice);
	printf("Tax%44.2lf\n", tax);
	printf("Total%42.2lf\n", totalPrice + tax);

	printf("Thank you for shopping at Seneca!\n\n");

	return totalPrice;
}

void getTopSellers(struct StockRecord storestock[], int numstockitems, struct SalesRecord topSellers[], int num, int loopVar) {

	struct SalesProductTemp topSellerTmp[MAX_ITEMS_IN_SALE] = { 0 };
	struct SalesProductTemp temp;

	char categoryName[15] = { '\0' };

	int currentEmnt = 0;

	for (int i = 0; i < soldItems; i++) {

		if (strcmp(saleStock[i].strCategory, strcpy(categoryName, catString(loopVar + 1))) == 0) {

			strcpy(topSellerTmp[currentEmnt].productName, saleStock[i].name);
			topSellerTmp[currentEmnt].qty = saleStock[i].qty;
			currentEmnt++;
		}
	}

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {

			if (topSellerTmp[i].qty < topSellerTmp[j].qty) {

				temp = topSellerTmp[i];
				topSellerTmp[i] = topSellerTmp[j];
				topSellerTmp[j] = temp;
			}
		}
		strcpy(topSellers[i].productName, topSellerTmp[i].productName);
		topSellers[i].quantity = topSellerTmp[i].qty;
	}
}

void printTopSellers(struct StockRecord storeStock[], struct SalesRecord topSellers[], int num, int loopVar) {

	char categoryName[25] = { '\0' };

	strcpy(categoryName, catString(loopVar + 1));
	strcat(categoryName, " ");

	if (num == 3) {

		char str1[50] = " Top 3 sellers in ";
		strcat(str1, categoryName);
		centreText(50, '-', str1);
	}
	else if (num == 2)
	{
		char str1[50] = " Top 2 sellers in ";
		strcat(str1, categoryName);
		centreText(50, '-', str1);
	}

	printf("\n%4s%30s%8s\n", "Rank", "Product", "Sales");

	for (int i = 0; i < num; i++) {

		if (topSellers[i].quantity > 0)
		{
			printf("%4d%30s%8.2lf\n", i + 1, topSellers[i].productName, topSellers[i].quantity);
		}
		else
		{
			printf("%4d%30s%8.2lf\n", i + 1, "<none>", topSellers[i].quantity);
		}
	}
}