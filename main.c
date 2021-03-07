/*
 ============================================================================
 Name        : Assignment02 - MiniGroup Project - Group A
 Author(s)   : Isis Frazier, Jordan Johnson, Sam Kauffman, Aarushi Singh
 Date		 : 3/05/2021
 Copyright   : Copyright 2021 MIT License
 Description : Assignment 02 to take input files of employees, salaries, and satisfaction levels.
 	 Split into a client thread space and server thread space.  Where the client is asking input of the user
 	 to lookup the information from the server process.  Server should traverse the input files in parallel
 	 and return the client via message queues.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "header.h"

/**
 * Arguments:
 * 		argc - count of input arguments to your program.
 * 		argv - pointer to all the input arguments.
 * 		argv[1] = employees file
 *		argv[2] = satisfaction_level file
 *		argv[3] = salaries file
 * 		argv[4] = history file
 *
 * Return:
 *		0 for Success.
 *
 */
int main(int argc, char **argv) {
	printf("Welcome to Group A's Mini Group Project\n");

	pthread_t clientThread, serverThread;

	struct inputFiles *files = (struct inputFiles*) malloc(sizeof(struct inputFiles));
	files->employeeFile = argv[1];
	files->satisfactionFile = argv[2];
	files->salaryFile = argv[3];

	//Create Server Initialization
	pthread_create(&serverThread, NULL, serverInit, (void*) files);

	//Create Client Initialization
	pthread_create(&clientThread, NULL, clientManagerInit, argv[4]);

	//Monitor for cleanup.

	//wait for the completion of server and client
	pthread_join(clientThread, NULL);

	//if the client is done...lets kill the server
	pthread_exit(&serverThread);

	// exit the current thread
	pthread_exit(NULL);


	printf("Thanks for visiting.  Goodbye;");
	return 0;
}
