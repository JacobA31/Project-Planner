/********* main.c ********

	Student Name 	= Jacob Aydin
	Student Number	= 101264856
*/

// Includes go here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a1_functions.h"

int main()
{
	// Your code goes here!
	float budget, dur;
	printf("Welcome to ABC Project Tracker \nEnter total project's budget:");
	scanf("%f", &budget);

	while (budget < 0)
	{
		printf("-------------------------------------\nThe value you entered is wrong \n Enter a positive value: ");
		scanf("%f", &budget);
	}

	printf("Enter total project's duration in weeks:");
	scanf("%f", &dur);

	while (dur < 0)
	{
		printf("-------------------------------------\nThe value you entered is wrong \n Enter a positive value: ");
		scanf("%f", &dur);
	}

	milestone_t arr[6];

	arr[0].cost = budget;
	arr[0].time = dur;
	arr[0].completed = 0;
	strcpy(arr[0].name,"Planned Details");
	number_of_employees(&arr[0]);
	printf("The planned number of employees needed is: %hu\n", arr[0].num_employees);

	float new_bud = budget / 5;
	arr[1] = init_milestone("Technical requirements", new_bud);
	arr[2] = init_milestone("System Design", new_bud);
	arr[3] = init_milestone("Software Development", new_bud);
	arr[4] = init_milestone("Testing", new_bud);
	arr[5] = init_milestone("Product release", new_bud);

	int chc = 6;
	while (chc != 0)
	{
		print_menu();

		scanf("%d", &chc);
		printf("\nYour choice is: %d", chc);
		if (chc < 0 || chc > 5)
		{
			printf("\n----------------------------------------");
			printf("\nThe value you entered is wrong \nEnter a value between 0 and 5:");
			scanf("%d", &chc);
		}
		if (chc > 0 && chc <= 5)
		{
			if (arr[chc].completed == 0)
			{
				print_stats(arr[chc]);
				update_stats(arr, chc);
			}
			else if (arr[chc].completed == 1)
			{
				print_stats(arr[chc]);
				printf("\n-----------------------------------");
				printf("\n%s milestone is completed cannot be updated", arr[chc].name);
				printf("\n-----------------------------------");
			}
		}
		if (chc == 0)
		{
			int fin =0;
			for (int k =1; k<=5; k++){
				fin += arr[k].completed;
			}
			
			if(fin == 5){
				arr[0].completed = 1;
			}

			print_stats(arr[0]);

			if (arr[0].completed == 0)
			{
				char ans;
				printf("\nThe project is not completed. Do you want to continue working on the project?: (Y/N)");
				scanf(" %c", &ans);
				if (ans == 'Y')
				{
					chc = 1;
				}
			}
		}
	}

	float total = 0;
	for (int j = 1; j <= 5; j++)
	{
		total += arr[j].cost;
	}
	printf("\n--------------------------- Final Project's Performance--------------------");
	if (total <= budget)
	{
		printf("\nThe project's cost is below budget!");
	}
	else
	{
		printf("\nThe project's cost is above budget!");
	}
	printf("\nPlanned budget: %f", budget);
	printf("\nActual Cost: %f", total);
	printf("\n---------------- The program will quit now! Goodbye! ----------------");
}
