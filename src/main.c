#include <stdlib.h>
#include <unistd.h>
#include "jansson_wrapper.h"

int main (int argc, char const *argv[])
{
	JanssonWrapper *jan = NULL;

	if (!isatty(STDIN_FILENO))
	{
	   jan = loadJson(stdin);

	   printf("%s%s%s\n", "Value for key : ", "walls-color = ", getString(jan, "walls-color"));
	   printf("%s%s%i\n", "Value for key : ", "num-rows = ", getInt(jan, "num-rows"));
	   printf("%s%s%s\n", "Value for key : ", "with-solution = ", getBool(jan, "with-solution") ? "true" : "false");
	   printf("%s%s%i\n", "Value for key : ", "start (first element) = ", getIntArray(jan, "start")[0]);
	   printf("%s%s%i\n", "Value for key : ", "start (second element) = ", getIntArray(jan, "start")[1]);
	   printf("%s%s%i\n", "Value for key : ", "end (first element) = ", getIntArray(jan, "end")[0]);
	   printf("%s%s%i\n", "Value for key : ", "end (second element) = ", getIntArray(jan, "end")[1]);
	}else{
		printf("%s\n", "No json file to process.");
	}

	if (jan != NULL)
		free(jan);	
	
	return EXIT_SUCCESS;	
}

