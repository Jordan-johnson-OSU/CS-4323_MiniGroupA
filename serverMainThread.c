/*
 * serverMainThread.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "header.h"

/**
 * Arguments:
 * 			char *nameFile -> name and relative path of tab delimited text file containing employee data.
 * Return:
 * 			struct EmployeeList -> struct of employees loaded from file
 */
struct EmployeeList* loadEmployees(char *nameFile) {

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

	int i = 0;
	while (!feof(file)) {
		//printf("Scanning row %d\n", i);

		//pull new line from each file
		fscanf(file, "%[^\n]", line);

		fgetc(file);

		employees[i].id = strtol(line, "\t", 10);
		employees[i].employeeName = strtok(NULL, "\r\n");

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
		//printf("Scanning row %d\n", i);

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

		satisfactionLevels[i].id = strtol(line, "\t",10);
		satisfactionLevels[i].satisfaction_level = strtol(line, "\t",10);
		satisfactionLevels[i].number_project = strtol(line, "\t",10);
		satisfactionLevels[i].average_monthly_hours = strtol(line, "\t",10);
		satisfactionLevels[i].time_spend_company_in_yrs = strtol(line, "\t",10);
		satisfactionLevels[i].work_accident = strtol(line, "\t",10);
		satisfactionLevels[i].promotion_last_5years =  strtol(NULL, "\r\n",10);

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

		salaries[i].id = strtol(line, "\t",10);
		salaries[i].jobTitle = strtok(line, "\t");
		salaries[i].basePay = strtof(line, "\t");
		salaries[i].overtimePay = strtof(line, "\t");
		salaries[i].benefit = strtof(line, "\t");
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
void *serverInit(struct inputFiles *files) {
	printf("serverInit\n");
	//Read the 3 files or 1 excel file into memory spaces; probably just 3 text files would be easiest.
	struct EmployeeList *employeeList = loadEmployees(files->employeeFile);
	struct SalaryList *salaryList = loadSalaries(files->salaryFile);
	struct SatisfactionLevelList *satisfactionLevelList = loadSatisfactionLevels(files->satisfactionFile);

	printf("Employee List has %d records.\n", employeeList->employeeCount);

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


}
