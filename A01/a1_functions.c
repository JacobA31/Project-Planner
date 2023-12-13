/********* definitions.c ********
	
	Student Name 	= Jacob Aydin
	Student Number	= 101264856
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "a1_functions.h"
// Your solution goes here
void number_of_employees(milestone_t *project_details){
	int sal = 40*25 * project_details->time;
	(*project_details).num_employees = round((*project_details).cost / sal);
}

milestone_t init_milestone(char stage_name[], float assigned_budget){
	milestone_t spec;
	strcpy(spec.name,stage_name);
	spec.cost = assigned_budget;
	spec.time = 0.0;
	spec.num_employees = 0;
	spec.completed = 0;	
	return spec;
}


void print_menu(void){
	printf("\n--------------------------");
	printf("\nWhich milestone you want to update? (0 to exit):");
	printf("\n1. Technical requirements");
	printf("\n2. System Design");
	printf("\n3. Software Development");
	printf("\n4. Testing");
	printf("\n5. Product Release ->");
}

void print_stats(milestone_t details){
	printf("\n--------- Milestone Stats ---------");
	printf("\nBelow is '%s' current stats:", details.name);
	printf("\n-----------------------------------");
	
	printf("\nActual time: %f",details.time);
	printf("\nActual number of employees: %d",details.num_employees);
	printf("\nActual cost: %f",details.cost);
	
	if(details.completed == 1){
		printf("\nCompleted: Yes");
	}
	if (details.completed == 0){
		printf("\nCompleted: No");
	}
}

void update_stats(milestone_t milestone_array[], int milestone_num){
	printf("\n--------- Update Stats ---------");
	printf("\nEnter the milestone's actual time:");
	scanf("%f",&milestone_array[milestone_num].time);

	printf("\nEnter the milestone's actual number of employees:");
	scanf("%d",&milestone_array[milestone_num].num_employees);

	milestone_array[milestone_num].cost = (milestone_array[milestone_num].num_employees * milestone_array[milestone_num].time * 40 * 25);
	printf("\nActual cost: %f", milestone_array[milestone_num].cost);

	char response;
	printf("\nIs this milestone complete?: (Y/N)");
	scanf(" %c",&response);
	
	if (response == 'Y'){
		milestone_array[milestone_num].completed = 1;
	}
	else if (response == 'N'){
		milestone_array[milestone_num].completed = 0;
	}

	printf("\nStats Updated!");
}

void check_project_completion(milestone_t milestone_array[], int num_milestones){
	int chck;
	for(int i =1; i<=5; i++){
		chck += milestone_array[i].completed;
	}
}