///*Design and code a program that displays the bit pattern for an integer that occupies a single byte.  Your program prompts the user for an integer between 0 and 255 and displays the 8-bit binary equivalent of the integer.  You may assume that the user enters a valid number.
//
//The output from your program might look something like:
//
// Enter an integer between 0 and 255 : 65
// The binary equivalent of 65 is 01000001
//*/
//
//#include <stdio.h>
//
//int main()
//{
//	int a = 128, decimal, num, b;
//
//	printf("Enter a number: ");
//	scanf("%d", &decimal);
//
//	int c = 0;
//
//	while (a != 0)
//	{
//		if (b = decimal / a == 1)
//		{
//			printf("%d", b);
//		}
//
//		else
//		{
//			printf("%d", c);
//		}
//
//		decimal = decimal % a;
//		a = a / 2;
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int getEven(int *min, int *max);
//
//int main()
//{
//	int min = 0, max = 100;
//
//	getEven(&min, &max);
//	
//	printf("%d %d",max,min);//this changes the value of max and min as it return the values from the getEven function
//	
//	return 0;
//}
//
//int getEven(int *min, int *max)
//{
//
//	int* num;
//
//	//below is STACK allocation
//
//	//int i;
//	//num = &i; 
//	
//	// OR
//
//	//below is heap allocation
//	num = malloc(sizeof(int)); //to use pointer var in scanf, you either need to explicitly define a variable and assign address of that variable OR use DMA to assign the address of an int var to a pointer. ALSO, remember scanf need an address of something, to store the value into that variable from useer
//
//	int *i = min;
//
//	while (*i != 1)
//	{
//		printf("\nEnter a number between 0 and 100: ");
//		scanf("%d", num);
//
//		*num = *num % 2;
//
//		if (*num == 0)
//		{
//			printf("\nYou entered an even number, goodbye.\n");
//			*i++;
//			break;	
//		}
//
//		else
//		{
//			printf("\nInvalid Entry. Please try again.\n");
//		}
//	}
//	free(num);
//
//	*max = 10;
//	*min = 5;
//	
//	return 0;
//}
//
//


/* Concepts
   1. C Library Functions
   2. random number generation
   3. <stdlib.h>, <time.h>

   updated on 11/09/2020
 */

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <time.h>
//#include <stdio.h>
//
//int main(void) {
//
//    int i, j, m, rnum;
//
//    //struct tm * systemtime;
//    //time_t      t;
//
//    /* random number generation */
//
//    srand(time(NULL)); /* the seed of random number generation (the current system time)
//                            <stdlib.h>, <time.h> */
//
//    for (i = 1; i <= 5; i++) {
//
//        for (j = 1; j <= 12; j++) {
//            m = rand();  /* range: 0 - RAND_MAX */ /* <stdlib.h> */
//
//            rnum = (m % 5) + 11;  /* random numbers: 1, 2, 3, 4, 5, 6 */
//
//            printf("%3d", rnum);
//        }
//
//        printf("\n");
//    }
//
//    /* FOR FUN (NOT PART OF THE COURSE) */
//
//    /* get system time */
//
//    /*
//
//    t = time(NULL);
//    systemtime = localtime( &t );
//
//    printf( "\nTime:%2d:%2d:%2d\n", (*systemtime).tm_hour,
//                    (*systemtime).tm_min,
//                    (*systemtime).tm_sec );
//
//    printf( "tm_mon: %d, tm_mday: %d, tm_year: %d\n",
//        systemtime->tm_mon, systemtime->tm_mday, systemtime->tm_year );
//
//    printf( "\nDate:%2d/%2d/%2d\n", (systemtime->tm_mon)+1,
//                     systemtime->tm_mday,
//                    (systemtime->tm_year)-100+2000 );
//    */
//    /* year: since 1900 */
//
//    return 0;
//}

//void main(void)
//{
//	int number;
//	int number_other;
//	char any_char;
//
//	printf("please enter an integer: ");
//	
//	scanf("%*d %d %d %*d %*c %*c %c", &number, &number_other, &any_char);
//	
//	printf("The number is: %d\n", number);
//	printf("The char is: %c\n", any_char);
//	printf("The number other entered is: %d\n", number_other);
//
//	return 0;
//}

//#include <stdio.h>
//
//int  func1(int a, int b);
//void func2(int* x, int y);
//
//int main(void) {
//
//    int num1, num2, answer;
//
//    num1 = 111;
//    num2 = 222;
//
//    answer = func1(num1, num2);
//    printf("1. num1=%d, num2=%d, answer=%d\n", num1, num2, answer);
//
//    func2(&num1, num2);
//    printf("2. num1=%d, num2=%d, answer=%d\n", num1, num2, answer);
//    return 0;
//}
//
//int func1(int a, int b) {
//    int sum;
//
//    sum = a + b;
//    a += 500;
//    printf("func1: %d, %d\n", a, b);
//    return sum;
//}
//
//void func2(int* x, int y) {
//    int d;
//
//    d = (*x) - y;
//    *x += 100;
//    y = d;
//    printf("func2: %d, %d\n", *x, y);
//}

//#include <stdio.h>
//#include <string.h>
//void centreText(int num, char str, char str1[]);
//
//int main() {
	/*int j, k;
	double data = 23.45;

	for (j = 1; j < 3; j = j + 1) {
		for (k = 2; k <= 5; k = k + 2) {

			if (((int)data) % 3 == 1) {
				data++;
			}
			else {
				data += 2;
			}
		}
	}
	printf("abc: j: %d, k: %d, data: %.2lf\n", j, k, data);
	return 0;*/



// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
//
// #define NAME_MAX 25
// #define MAX_FILLS 5
// #define NUM_VEHICLES 2
//
// struct FillUp
// {
//     double startOdometer, endOdometer;
//     double fuelUsed;
// };
//
// struct DrivingRecord
// {
//     char make[NAME_MAX + 1];
//     char model[NAME_MAX + 1];
//     int numFills;
//     struct FillUp fillups[MAX_FILLS];
// };
//
// double getAverage(struct DrivingRecord recs[], int nrecs, struct DrivingRecord* best, struct DrivingRecord* worst)
// {
//     int i, j, worstPos = -1, bestPos = -1;
//     double dist, fillDist, economy, totalEconomy = 0.0, worstEconomy = -1, bestEconomy = 9999;
//
//     for (i = 0; i < nrecs; i++)
//     {
//         dist = 0;
//         economy = 0;
//         for (j = 0; j < recs[i].numFills; j++)
//         {
//             fillDist = recs[i].fillups[j].endOdometer - recs[i].fillups[j].startOdometer;
//             economy += recs[i].fillups[j].fuelUsed / fillDist * 100.0;
//             dist += fillDist;
//         }
//         economy /= recs[i].numFills;
//         if (economy < bestEconomy)
//         {
//             bestEconomy = economy;
//             bestPos = i;
//         }
//         if (economy > worstEconomy)
//         {
//             worstEconomy = economy;
//             worstPos = i;
//         }
//         totalEconomy += economy;
//     }
//    *best = recs[bestPos];
//	*worst = recs[worstPos];
//	     return totalEconomy / nrecs;
//	 }
//
//int main(void)
// {
//     struct DrivingRecord guzzlers[] = {
//         {"Ford", "F150", 2, {{21992, 22580, 72.1}, {22680, 23011, 68.5}} },
//         {"Cadillac", "Escalade", 1,{10687, 11219, 82.8}}
// };
//     struct DrivingRecord top, bottom;
//     double avg;
//
//     avg = getAverage(guzzlers, NUM_VEHICLES, &top, &bottom);
//     printf("Fleet average is %.2lf l/100km with the best being %s %s and the worst being %s %s\n",
//         avg, top.make, top.model, bottom.make, bottom.model);
//
//     return 0;
//}

/*
Example Execution(C):
Enter a word, synonym, and related factor (example: Structure|House|1)
Enter 'Q' by itself to exit (example: Q)
Add to thesaurus [word|synonym|factor]: Structure|House|1
Add to thesaurus [word|synonym|factor]: Vehicle|Car|1
Add to thesaurus [word|synonym|factor]: Structure|Building|1
Add to thesaurus [word|synonym|factor]: Vehicle|Truck|1
Add to thesaurus [word|synonym|factor]: Feline|Tiger|2
Add to thesaurus [word|synonym|factor]: error
!!! Invalid input !!!
Enter a word, synonym, and related factor (example: Structure|House|1)
Enter 'Q' by itself to exit (example: |)
Add to thesaurus [word|synonym|factor]: Structure|Shed|3
Add to thesaurus [word|synonym|factor]: Q
Thesaurus Data:
 1) Structure
         1. House (Factor:1)
         2. Building (Factor:1)
         3. Shed (Factor:3)
 2) Vehicle
         1. Car (Factor:1)
         2. Truck (Factor:1)
 3) Feline
         1. Tiger (Factor:2)
Application exiting... Goodbye!
*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//#define MAX_SZ 20
//#define MAX_LINE 50
//#define MAX_ENTRIES 100
//
//struct Synonym
//{
//    char name[MAX_SZ + 1];
//    int relatedFactor; // 1=highly | 2=moderately | 3=loosely
//};
//
//struct WordInfo
//{
//    char word[MAX_SZ + 1];
//    struct Synonym synonyms[MAX_ENTRIES];
//    int synonymCount;
//};
//
//void clearInputBuffer(void)
//{
//    while (getchar() != '\n')
//        ; // empty on purpose
//}
//
//int add(const char word[], const char synonym[], const int relatedFactor, struct WordInfo thesaurus[], int arrSize)
//{
//    int addedWord = 0, found = 0, i;
//
//    // lookup for existing word
//    for (i = 0; i < arrSize && !found; i++)
//    {
//        // found match
//        if (!strcmp(word, thesaurus[i].word))
//        {
//            strcpy(thesaurus[i].synonyms[thesaurus[i].synonymCount].name, synonym);
//            thesaurus[i].synonyms[thesaurus[i].synonymCount].relatedFactor = relatedFactor;
//            thesaurus[i].synonymCount++;
//            found = 1; // toggle exit from loop
//        }
//        // not found and Empty slot: add to thesaurus.word array | set thesaurus.synonymCount to 1 | set result to 1
//        else if (thesaurus[i].word[0] == '\0')
//        {
//            addedWord = 1; // toggle return value to 1 (added)
//            found = 1; // toggle exit from loop
//            strcpy(thesaurus[i].word, word);
//            strcpy(thesaurus[i].synonyms[0].name, synonym);
//            thesaurus[i].synonyms[0].relatedFactor = relatedFactor;
//            thesaurus[i].synonymCount++;         //needs to be ++ instead of just thesaurus[i].synonyCount;
//        }
//    }
//
//    return addedWord;
//}
//
//int main(void)
//{
//    struct WordInfo thesaurus[MAX_ENTRIES] = { { {0} } };
//    int i, j, quitting, numEntries = 0, valid;
//
//    char word[MAX_SZ + 1], synonym[MAX_SZ + 1];
//    int relatedFactor;
//
//    // -----------------------------
//    // Instructions
//    printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
//    printf("Enter 'Q' by itself to exit (example: Q)\n\n");
//
//    do
//    {
//        // -----------------------------
//        // Prompt:
//        printf("Add to thesaurus [word|synonym|factor]: ");
//        valid = scanf("%20[^|\n]|%20[^|]|%d", word, synonym, &relatedFactor);
//        clearInputBuffer();
//
//        quitting = (valid == 1 && strcmp("Q", word) == 0); //needs to be && instead of ||
//        if (quitting)
//        {
//            // -----------------------------
//            // Display the thesaurus
//            printf("\n");
//            printf("Thesaurus Data:\n");
//            for (i = 0; i < numEntries; i++)
//            {
//                printf("%2d) %s\n", i + 1, thesaurus[i].word);
//                for (j = 0; j < thesaurus[i].synonymCount; j++)
//                {
//                    printf("\t%2d. %s (Factor:%d)\n", j + 1, thesaurus[i].synonyms[j].name, thesaurus[i].synonyms[j].relatedFactor);
//                }
//            }
//            printf("\n");
//        }
//        else if (valid == 3)
//        {
//            // -----------------------------
//            // If new word was added, returns 1, otherwise 0
//            numEntries += add(word, synonym, relatedFactor, thesaurus, MAX_ENTRIES); // error here, needs to be numEnteries += instead of numEntries = ......
//        }
//        else
//        {
//            // -----------------------------
//            // Show error message
//            printf("\n");
//            printf("!!! Invalid input !!!\n");
//            printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
//            printf("Enter 'Q' by itself to exit (example: |)\n\n");
//        }
//
//    } while (!quitting);
//
//    // -----------------------------
//    // Show goodbye
//    printf("Application exiting... Goodbye!\n");
//
//    return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
//
//int main(void)
//{
//    char str1[] = "Jake";
//    char str2[] = "Fred";
//    char str3[] = "Mary";
//    strcpy(str1, str2);
//    if (strcmp(str1, str2))
//    {
//        printf("Yes\n");
//    }
//    else if (strcmp(str2, str1))
//    {
//        printf("YesYes\n");
//    }
//    else if (strcmp(str3, "Mary"))
//    {
//        printf("Maybe\n");
//    }
//    else if (strcmp(str1, str3))
//    {
//        printf("No\n");
//    }
//    else
//    {
//        printf("NoNo\n");
//    }
//    return 0;
//}
//
//#include <stdio.h>
//int count(char aString[], int* total);
//
//void main()
//{
//    int num = 0;
//
//    printf("length: % d, ", count("C program 12 34", &num));
//    printf("total number of blank spaces : %d\n", num);
//
//}
//int count(char aString[], int* total) {
//
//    int len;
//
//    len = strlen(aString);
//
//    for (int i = 0; i < len; i++)
//
//    {
//        if (aString[i] == ' ')
//        {
//            *total += 1;
//        }
//    }
//    return len;
//}
//
//#include <stdio.h>
//double getDouble(double* min, double* max);
//void clear(void);
//
//void main()
//{
//    double min, max, value;
//
//    printf("Enter a min and max number: ");
//    scanf("%lf%lf", &min, &max);
//
//    value = getDouble(&min, &max);
//    printf("You entered %.2lf which is between the number you entered.", value);
//}
//
//double getDouble(double* min, double* max)
//{
//    double num;
//    char str;
//    int keeptrying = 0;
//    do {
//        printf("Enter a number between %.2lf and %.2lf: ", *min, *max);
//        int rc = scanf("%lf%c", &num, &str);
//
//        if (rc == 0) {
//
//            printf("Input mismatch. Enter integers only.\n");
//            clear();
//        }
//        else if (str != '\n') {
//
//            printf("Trailing characters not allowed.\n");
//            clear();
//        }
//        else if (num < *min || num > * max) {
//
//            printf("Out of range\n");
//        }
//        else {
//
//            keeptrying = 1;
//        }
//
//    } while (keeptrying == 0);
//
//    return num;
//}
//
//void clear(void) {
//
//    while (getchar() != '\n');
//}