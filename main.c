/*
 * main.c
 *
 */

#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "header.h"

/**
 * Arguments:
 * 		argc - count of input arguments to your program.
 * 		argv - pointer to all the input arguments.
 *
 * Return:
 *		0 for Success.
 *
 */
int main(int argc, char **argv) {

	//argv[1] = employees file
	//argv[2] = satisfaction_level file
	//argv[3] = salaries file
	//argv[4] = history file

	pthread_t clientThread, serverThread;

	//Create Server Initialization
	pthread_create(&serverThread, NULL, serverInit, argv[1],argv[2],argv[3]);

	//Create Client Initialization
	pthread_create(&clientThread, NULL, clientManagerInit, argv[4]);

	//Monitor for cleanup.

	//wait for the completion of server and client
	pthread_join(clientThread, NULL);

	//if the client is done...lets kill the server
	pthread_exit(serverThread);

	// exit the current thread
	pthread_exit(NULL);

}
