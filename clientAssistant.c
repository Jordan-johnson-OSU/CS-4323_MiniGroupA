/*
 * clientAssistant.c
 *
 */
#include <stdlib.h>
#include <string.h>

#include "header.h"

struct historyData readHistoryFile(char **file){
	return 0;
}

/**
 * File should only hold 10 records, if full delete the oldest entry.
 */
void writehistory(struct historyData *data){

}

void assistantInit(){
	//ReadHistoryFile
	//IF information found:
		//Print to separate terminal
	//Else
		//Request to the server via message queue.

		//Wait for return from Server processes.

		//Read information from the message queue.

		//Add the information to history file

		//Print to separate terminal
}