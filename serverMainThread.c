/*
 * serverMainThread.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#include "header.h"

/**
 * Arguments:
 * 			char *nameFile -> name and relative path of tab delimited text file containing employee data.
 * Return:
 * 			struct EmployeeList -> struct of employees loaded from file
 */
struct EmployeeList* loadEmployees(char *nameFile) {
	printf("\tLoadEmployee \n");

	//Let's set a max of 150000 items to read in.
	struct Employee *employees = (struct Employee*) malloc(
			150000 * sizeof(struct Employee));

	FILE *file = fopen(nameFile, "r");

	if (file == NULL) {
		perror("File is null");
		exit(EXIT_FAILURE);
	}

	char chunk[256];
	size_t len = sizeof(chunk);
	char *line = malloc(len);

	if (line == NULL) {
		perror("Unable to allocate memory for the line buffer.");
		exit(1);
	}

	char value[100];
	char *eptr;
	int i = 0;
	while (!feof(file)) {
//		printf("\tScanning row %d\n", i);

		//pull new line from each file
		fscanf(file, "%[^\n]", line);

		fgetc(file);

		strcpy(value, line);

		employees[i].id = strtol(value, &eptr, 10);
		employees[i].employeeName = eptr;

		i++;
	}

	// close file
	fclose(file);

	//Build the product list based on what was identified in the file.
	struct EmployeeList *employeeList = (struct EmployeeList*) malloc(
			sizeof(struct EmployeeList) + (i * sizeof(struct Employee)));

	employeeList->employeeCount = i;
	employeeList->employees = employees;

	return employeeList;
}


/**
 * Arguments:
 * 			char *nameFile -> name and relative path of tab delimited text file containing satisfaction level data.
 * Return:
 * 			struct SatisfactionLevelList -> struct of satisfaction levels loaded from file
 */
struct SatisfactionLevelList* loadSatisfactionLevels(char *nameFile) {
	printf("\tloadSatisfactionLevels \n");

	//Let's set a max of 150000 items to read in.
	struct SatisfactionLevel *satisfactionLevels = (struct SatisfactionLevel*) malloc(
			150000 * sizeof(struct SatisfactionLevel));

	FILE *file = fopen(nameFile, "r");

	if (file == NULL) {
		perror("File is null");
		exit(EXIT_FAILURE);
	}

	char chunk[256];
	size_t len = sizeof(chunk);
	char *line = malloc(len);

	if (line == NULL) {
		perror("Unable to allocate memory for the line buffer.");
		exit(1);
	}

	int i = 0;
	while (!feof(file)) {
//		printf("Scanning row %d\n", i);

		//pull new line from each file
		fscanf(file, "%[^\n]", line);

		fgetc(file);

		//Id	satisfaction_level	number_project	average_monthly_hours	time_spend_company_in_yrs	Work_accident	promotion_last_5years

//		int SL_id = strtol(line, "\t");
//		float SL_level = strtof(line, "\t");
//		int SL_number_project = strtol(line, "\t");
//		int SL_average_monthly_hours = strtol(line, "\t");
//		int SL_time_spend_company_in_yrs = strtol(line, "\t");
//		int SL_accident = strtok(line, "\t");
//		char *promo = strtok(NULL, "\r\n");

		satisfactionLevels[i].id = atol(strtok(line, "\t"));
		satisfactionLevels[i].satisfaction_level = atol(strtok(line, "\t"));
		satisfactionLevels[i].number_project = atol(strtok(line, "\t"));
		satisfactionLevels[i].average_monthly_hours = atol(strtok(line, "\t"));
		satisfactionLevels[i].time_spend_company_in_yrs = atol(strtok(line, "\t"));
		satisfactionLevels[i].work_accident = atol(strtok(line, "\t"));
		satisfactionLevels[i].promotion_last_5years =  atol(strtok(line, "\r\n"));

		i++;
	}

	// close file
	fclose(file);

	//Build the product list based on what was identified in the file.
	struct SatisfactionLevelList *list = (struct SatisfactionLevelList*) malloc(
			sizeof(struct SatisfactionLevelList) + (i * sizeof(struct SatisfactionLevel)));

	list->satisfactionLevelCount = i;
	list->satisfactionLevels = satisfactionLevels;

	return list;
}


/**
 * Arguments:
 * 			char *nameFile -> name and relative path of tab delimited text file containing salary data.
 * Return:
 * 			struct SalaryList -> struct of salary loaded from file
 */
struct SalaryList* loadSalaries(char *nameFile) {
	printf("\tloadSalaries \n");
	//Let's set a max of 150000 items to read in.
	struct Salary *salaries = (struct Salary*) malloc(
			150000 * sizeof(struct Salary));

	FILE *file = fopen(nameFile, "r");

	if (file == NULL) {
		perror("File is null");
		exit(EXIT_FAILURE);
	}

	char chunk[256];
	size_t len = sizeof(chunk);
	char *line = malloc(len);

	if (line == NULL) {
		perror("Unable to allocate memory for the line buffer.");
		exit(1);
	}

	int i = 0;
	while (!feof(file)) {
		//printf("Scanning row %d\n", i);

		//pull new line from each file
		fscanf(file, "%[^\n]", line);

		fgetc(file);

		//Id	JobTitle	BasePay	OvertimePay	Benefit	Status

		salaries[i].id = atol(strtok(line, "\t"));
		salaries[i].jobTitle = strtok(line, "\t");
		salaries[i].basePay = atof(strtok(line, "\t"));
		salaries[i].overtimePay = atof(strtok(line, "\t"));
		salaries[i].benefit = atof(strtok(line, "\t"));
		salaries[i].status =  strtok(NULL, "\r\n");

		i++;
	}

	// close file
	fclose(file);

	//Build the product list based on what was identified in the file.
	struct SalaryList *list = (struct SalaryList*) malloc(
			sizeof(struct SalaryList) + (i * sizeof(struct Salary)));

	list->salarycount = i;
	list->salaries = salaries;

	return list;
}



/**
 * Server Initialization
 */
void *serverInit(void *files) {
	printf("\tserverInit\n");
	//Read the 3 files or 1 excel file into memory spaces; probably just 3 text files would be easiest.
	struct EmployeeList *employeeList = loadEmployees(((struct inputFiles*) files)->employeeFile);
	struct SatisfactionLevelList *satisfactionLevelList = loadSatisfactionLevels(((struct inputFiles*) files)->satisfactionFile);
	struct SalaryList *salaryList = loadSalaries(((struct inputFiles*) files)->salaryFile);


	printf("Employee List has %d records.\n", employeeList->employeeCount);

	printf("Satisfaction List has %d records.\n", satisfactionLevelList->satisfactionLevelCount);

	printf("Salary List has %d records.\n", salaryList->salarycount);



	//loop until wanting to exit?

		//wait for message from assistant

		//Parse message from assistant

		//Find employee ID based on Name from File 1.

		//pthreads
		//serverSalaryThread
		//serverSatisfactionThread

		//Create Message queue and wait from the threads.

		//Build historyData record

		//Send data back to the assistant via message queue.

	//pthread_exit(NULL);
	return NULL;
}
