/* 7.32.c A program to simulate taking a poll on topics
 * Steven Gonzalez 009387092 Midterm3
 */
#include <stdio.h>

//global variable declarations
//topics array
char *topics[5] = {"Should Marijuana be legal?",
				   "Should Trump be President?",
				   "Should Abortions be illegal?",
				   "Restriction on Encryption?",
				   "Are Gas Prices too High?"};
//array to hold results and averages
int results[5][10] = {0};
double averages[5] = {0};

//tracks how many surveys have been taken 
int takenCount = 0;
//loop counters
int i, j; 

//function declarations
void printResults();
void printReady();
void sum();

//main function 
void main()	{
	//loop for 10 surveys
	for(i = 0; i < 10; i++)	{
		//call to print survey ready msg
		printReady();
		//ask each question in each survey 
		for(j = 0; j < 5; j++)	{
			printf("%s-: ", topics[j]); //topic prompt
			scanf("%d", &results[j][i]); //scan the input into the results
		}//end inner for loop
		//survey done increment counter for next survey
		takenCount++;
	}//end outter foor loop
	//print the results
	printResults();
}//end main function 

//printResults function 
void printResults()	{
	printf("\n\t-------------------------------"
			"---------------Results---------------"
		   "-------------------------------\n");
	printf("\tTopics\t\t\tPoll1\tPoll2\tPoll3\tPoll4\tPoll5\t"
		   "Poll6\tPoll7\tPoll8\tPoll9\tPoll10\tAverage");
	//get ready for the sum of each poll for averages
	double sum;
	printf("\n");
	//for each topic print the survey results
	for(i = 0; i < 5; i++)	{
		sum = 0;
		printf("%s\t", topics[i]);
		//prints the results for poll i
		for(j = 0; j < 10; j++)	{
			sum = sum + results[i][j];
			printf("%d\t", results[i][j]);
		}//end inner for loop
		//calculate averages
		double ave = (sum/10);
		averages[i] = ave;
		printf("|%.2f", ave);
		printf("\n");
	}//end outter for loop
	printf("\n");
	
	int poll = 0;
	//find the lowest average 
	double lowest = averages[0];
	for(i = 1; i < 5; i++)	{
		if(lowest > averages[i])	{
			lowest = averages[i];
			poll = i;
		}//end if statement 
	}//end for loop 
	printf("Lowest Average: %.2f for %s\n", lowest, topics[poll]);
	
	poll = 0;
	//find the highest average
	double highest = averages[0];
	for(i = 1; i < 5; i++)	{
		if(highest < averages[i])	{
			highest = averages[i];
			poll = i;
		}//end if statement 
	}//end for loop
	printf("Highest Average: %.2f for %s\n", highest, topics[poll]);
}// end print results function 

//printReady message function prints a prompt 
void printReady()	{
	printf("\nsurvey #: \n%d", takenCount);
	printf("\nReady to Start, Please rate on a scale of 1 - 10\n");
}//end printReady function 
