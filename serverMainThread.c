/*
 * serverMainThread.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "header.h"


struct Employee* loadEmployees(char *nameFile) {

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

		char *employeeId = strtok(line, "\t");

		char *employeeName = strtok(NULL, "\r\n");

		employees[i].id = atol(employeeId);
		employees[i].employeeName = employeeName;

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
 * Server Initialization
 */
void *serverInit(char **employeeFile, char **satisfactionFile, char **salaryFile) {
	//Read the 3 files or 1 excel file into memory spaces; probably just 3 text files would be easiest.

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
