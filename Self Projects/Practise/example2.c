//#include <stdio.h>
//#include <stdlib.h>
//
//void check(char* ptr, int count);
//
//int main()
//{	
//	int count=0;
//	char* ptr = (char*) malloc(sizeof(char) * 100);
//
//	*ptr = NULL;
//
//	for (int i = 0; i <= ptr[i]; i++)
//	{
//		printf("Enter a string and an integer: ");
//		scanf("%s", ptr[i]);
//
//		if (ptr[i] == 13)
//		{
//			break;
//		}
//	}
//
//	printf("Enter a number: \n");
//	scanf("%d", &count);
//
//	check(&ptr, count);
//
//	return 0;
//}
//
//void check(char *ptr, int count)
//{
//	int a = 0,num;
//	do
//	{
//		num = strlen(*ptr);
//
//		if (num == count)
//		{
//			for (int i = 0; i <= ptr[i]; i++)
//			{
//				if (ptr[i] >= 'A' && ptr[i] <= 'Z')
//				{
//					a++;
//				}
//			}
//		}
//		else
//		{
//			printf("please enter a string that has half the characters as upper-case alphabets and count to be same as the string's length\n");
//		}
//	} while (a != count / 2);
//
//	printf("The string is valid");
//}
//


//#include <stdio.h>
//int main()
//{
//	int i,a,sum=0;
//	printf("Enter a number: ");
//	scanf("%d", &a);
//	
//	for (i = a; i != 0; i--);
//	{
//		sum = sum + i;
//	}
//	while (i!=0)
//	{
//		sum = sum + i;
//		i--;
//	}
//
//	printf("%d", sum);
//
//	return 0;
//}

//Designand code a program that displays the bit pattern for an integer that occupies a single byte.Your program prompts the user for an integer between 0 and 255 and displays the 8 - bit binary equivalent of the integer.You may assume that the user enters a valid number.
//
//
//
//The output from your program might look something like :
//
//
//
//Enter an integer between 0 and 255 : 65
//The binary equivalent of 65 is 01000001
//int main()
//{
//    int a = 128, decimal, num, b;
//
//
//    printf("Enter a number: ");
//    scanf("%d", &decimal);
//
//    int c = 0;
//
//
//    while (a != 0)
//    {
//        if (b = decimal / a == 1)
//        {
//            printf("%d", b);
//        }
//
//        else
//        {
//            printf("%d", c);
//        }
//
//
//        decimal = decimal % a;
//        a = a / 2;
//    }
//
//
//    return 0;
//}


//#include<stdio.h>
//
//int main(void)
//{
//    int low, high;
//
//    printf("Enter the low end of the range: ");
//    scanf("%d", &low);
//
//    printf("\n");
//
//    printf("Enter the high end of the range: ");
//    scanf("%d", &high);
//
//    printf("\n");
//
//    for (int i = low; i <= high +1; i++)
//    {
//        for (int j = low; j <= high; j++)
//        {
//            if (i == low)
//            {
//                printf("   %d ", (j * 1));
//            }
//            if (i > low)
//            {
//                printf("%d    ", (j * (i-1)));
//            }
//        }
//        printf("\n");
//        
//        if (i != high +1)
//        {
//            printf("%d ", i);
//        }
//        
//    }
//    return 0;
//}



//#include <stdio.h>
//
//struct Student
//{
//	int num1;
//	float num2;
//};
//
//void main()
//{
//	const n = 4;
//
//	struct student s1[] =
//	{ {123, 23.45}, {1234, 23.56}, { 12, 23.54}, {12345, 23.57} };
//	
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %.2lf\n", s1[i].num1, s1[i].num2);
//	}
//
//	return 0;
// }


//#include <stdio.h>
//#include <string.h>
//
//int EAN(int ISBN);
//
//int main()
//{
//
//	int *p;
//	p = EAN(321197186);
//
//	for (int i = 0; i < 9; i++)
//	{
//		// concatenate the numbers to an int variable
//		//eg 9780 + the array itself
//	}
//	return 0;
//}
//
//int EAN(int ISBN)
//{
//	int number[9], index = 0, alpha = 38, arr[8];
//
//	while (ISBN != 0 && index < 9)
//	{
//		number[index] = ISBN % 10;
//		++index;
//		ISBN = ISBN / 10;
//	}
//
//	for (int i = 0; i < 8; i++)
//	{
//		if ((i+1) % 2 == 0)
//		{
//			arr[i] = number[i+1] * 1;
//		}
//
//		else
//		{
//			arr[i] = number[i+1] * 3;
//		}
//	}
//
//	for (int j = 0; j < 8; j++)
//	{
//		alpha = alpha + arr[j];
//	}
//	
//	alpha = alpha % 10;
//	number[0] = 10 - alpha;
//
//	return number;
//}

//#include <stdio.h>;
//
//int main()
//{
//	int immi, sum = 0, counter = 0;
//	float avg;
//	
//	do
//	{
//		printf("Number of immigrants in a month (0 to quit) : ");
//		scanf(" %d",&immi);
//		
//		if (immi > 0)
//		{
//			sum = sum + immi;
//			counter++;
//		}
//
//	} while (immi != 0);
//
//
//	printf("The average monthly immigration is (%d/%d) = %.2lf", sum,counter, avg = ((float)sum/counter));
//
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#define  MAX 5
//
///* an array parameter: a pointer!
//
//   updated on 3/01/2020
// */
//
//int increase(int data[], int delta); // data: an array parameter
//
//void show(int list[]);       // list: an array parameter
//
//void fill_array(int num[]);  // num: an array parameter
//
//float average(int z[]);
//
//int main(void) {
//
//    int scores[MAX] = { 100, 89, 75, 64, 55 };
//
//    int sum = 0;
//    float avg = 0;
//
//    show(scores);  // passing by address!
//
//    sum = increase(scores, 100);  // passing by address, passing by value
//
//    show(scores);  // passing by address
//
//    printf("sum = %d\n", sum);
//
//    /* Part 2 */
//
//    fill_array(scores); // passing by address
//
//    show(scores);
//    avg = average(scores);
//
//    printf("%.2lf \n", avg);
//
//    return 0;
//}
//
///* input and output parameter: data (an array parameter/a pointer)
//   input parameter: delta */
//int increase(int data[], int delta) {
//
//    int k, t = 0;
//
//    for (k = 0; k < MAX; k++) {
//
//        data[k] += delta; // Is 100 added to the array data?
//
//        t += data[k];
//    }
//    //data[0] = -2222; /* side effect! */ 
//
//    return t;
//}
//
///* input and output parameter: list (an array parameter/a pointer) */
//void show(int list[]) {
//
//    int j;
//
//    for (j = 0; j < MAX; j++) {
//        printf("%d ", list[j]);
//    }
//
//    printf("\n");
//}
//
//
///* input and output parameter: num */
//void fill_array(int num[]) {
//
//    int k;
//
//    for (k = 0; k < MAX; k++) {
//        printf("Enter an integer: ");
//        scanf("%d", &num[k]);
//    }
//}
//
//
///* input and output parameter: z */
//float average(int z[]) {
//
//    float total = 0;
//    int k;
//
//    for (k = 0; k < MAX; k++)
//        total += z[k];
//
//      
//    return (total / MAX);
//}


//#include<stdio.h>
//#define SZ 5
//
//int main(void)
//{
//    int arg1[SZ] = { 3, 4, 7, 2, 9 };
//    double arg2[SZ] = { 2.1, 3.2, 5.3, 7.2, 8.1 };
//    char operand[SZ] = { 'm', 'd', 'r', 'm', 'r' };
//    int i;
//    for (i = 0; i < SZ; i++)
//    {
//        switch (operand[i])
//        {
//        case 'm':
//            printf("%.2lf ", arg1[i] * arg2[i]);
//            break;
//        case 'd':
//            printf("%.2lf  ", (double)arg1[i] / arg2[i]);
//            break;
//        case 'r':
//            printf("%d  ", arg1[i] % (int)arg2[i]);
//            break;
//        default:
//            break;
//        }
//    }
//    printf("\n");
//    return 0;
//}


//#include <stdio.h>
//struct Numbers
//{
//    int streetNumber;
//};
//
//struct Contact
//{
//    struct Numbers numbers;
//};
//
//void updateContact(struct Contact contacts[]);
//void getContacts(struct Contact* pContact);
//void getNumbers(struct Numbers* pNumbers);
//
//int main()
//{
//    struct Contact contactArr[] = { 1, 2, 3, 4 };
//
//    /*for (int i = 0; i < 4; i++)
//    {
//        printf("%p", &contactArr[i]);
//    }*/
//    
//    updateContact(contactArr);
//
//    for (int i = 0; i < 4; i++)
//    {
//        printf("\n%d", contactArr[i].numbers.streetNumber);
//    }
//    return 0;
//}
//
//void updateContact(struct Contact contacts[])
//{
//   /* printf("Address of contacts[]\n");
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%p\n", &contacts[i]);
//    }*/
//    for (int i = 0; i < 4; i++)
//    {
//        getContacts(&contacts[i]);
//    }
//}
//
//void getContacts(struct Contact* pContact)
//{
//   /* printf("Address of pContact\n");
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%p\n", &pContact[i]);
//    }*/
//
//    getNumbers(&pContact->numbers);
//        //what arguments should I pass so that the pointer pNumbers gets correct argument and updates the values  
//}
//
//void getNumbers(struct Numbers* pNumbers)
//{
//   /* printf("Address of pNumbers\n");
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%p\n", &pNumbers);
//    }*/
//    pNumbers->streetNumber += 4;
//    //update the values of all 4 elements to 5, 6, 7, 8
//}

//#define n 4
//struct process
//{
//    struct segment {
//
//        struct page
//        {
//            int pid;
//            int p[4];
//        }pages[n];
//    }segments[n];
//}processes[3];
//
//
//int main()
//{
//    int a, b, c;
//    int k = 0;
//    for (a = 0; a < 3; a++)
//    {
//        for (b = 0; b < 4; b++)
//        {
//            for (c = 0; c < 4; c++)
//            {
//                k++;
//                processes[a].segments[b].pages[c].pid = k;
//                printf("Segment: %d, Page: %d, PID: %d\n", a, b, processes[a].segments[b].pages[c].pid);
//            }
//        }
//
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//void foo(int* x, int y);
//
//int main(void)
//{
//	int small, big;
//
//	small = 20;
//	big = 40;
//	foo(&small, big);
//
//	printf("2. small=%d, big=%d\n", small, big);
//	return 0;
//}
//
//
//void foo(int* x, int y)
//{
//	int d;
//	d = (*x);
//	d += y;
//	*x += d;
//	++y;
//	printf("foo: %d, %d\n", d, y);
//}