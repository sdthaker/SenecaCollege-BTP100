//==============================================
// Name:           Soham Thaker
// Student Number: 011-748-159
// Email:          sdthaker1@myseneca.ca
// Section:        NBB
// Workshop:       5 (at-home)
//==============================================
#include <stdio.h>
#define  _CRT_SECURE_NO_WARNINGS
#define SIZE 4

int main()
{
	struct Employee
	{
		int empID, age;
		double salary;
	};

	struct Employee emp[SIZE] = { { 0 } };
	int empSize = 0, option=0, ID = 0,update = -1,k=0;

	printf("---=== EMPLOYEE DATA ===---\n");

	do
	{
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");

		printf("\nPlease select from the above options: ");
		scanf("%d", &option);

		switch (option)
		{
			case 0:
			{
				printf("\nExiting Employee Data Program. Good Bye!!!\n");

				break;
			}
			case 1:
			{
					printf("\nEMP ID  EMP AGE EMP SALARY\n");
					printf("======  ======= ==========\n");
					int i;

					for (i = 0; i < SIZE; i++)
					{
						if (emp[i].empID > 0)
						{
							printf("%6d%9d%11.2lf\n", emp[i].empID, emp[i].age, emp[i].salary);
						}
					}
				break;
			}

			case 2:
			{
				printf("\nAdding Employee\n");
				printf("===============\n");

				if (empSize >= SIZE)
				{
					if (update != k)
					{
						printf("ERROR!!! Maximum Number of Employees Reached\n");
					}
				}
				else
				{

					printf("Enter Employee ID: ");
					scanf("%d", &emp[empSize].empID);

					printf("Enter Employee Age: ");
					scanf("%d", &emp[empSize].age);

					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[empSize].salary);

					empSize++;
				}

				if (update >= 0 && update <= SIZE)
				{
					printf("Enter Employee ID: ");
					scanf("%d", &emp[k-1].empID);

					printf("Enter Employee Age: ");
					scanf("%d", &emp[k-1].age);

					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[k-1].salary);

					update = -1;
				}

				break;
			}

			case 3:
			{
				printf("\nUpdate Employee Salary\n");
				printf("======================\n");
			
				int j,add, upd = 0;
				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &ID);
				
					add = 0;

					for (j = 0; j< SIZE && upd == 0; j++)
					{
						if (ID == emp[j].empID)
						{
							printf("The current salary is %5.2lf\n", emp[j].salary);

							printf("Enter Employee New Salary: ");
							scanf("%lf", &emp[j].salary);

							upd = 1;
						}

						else
						{
							add++;
						}

					}

					if (add >= SIZE) 
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}
				} while (upd == 0);

				break;
			}

			case 4:
			{
				printf("\nRemove Employee\n");
				printf("===============\n");

				int add, upd = 0;
				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &ID);

					add = 0;

					for (k = 0; k < SIZE && upd == 0; k++)
					{
						if (ID == emp[k].empID)
						{
							printf("Employee %d will be removed\n", emp[k].empID);
							upd = 1;
						}

						else
						{
							add++;
						}
					}

					if (add >= SIZE)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}
				} while (upd == 0);

				emp[k-1].empID = 0;
				update = k;

				break;
			}
				default:
				{
					printf("\nERROR: Incorrect Option: Try Again\n");
				}
		}
	} while (option != 0);

	return 0;
}


