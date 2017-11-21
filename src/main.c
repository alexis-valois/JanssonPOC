#include <stdlib.h>
#include <unistd.h>
#include "jansson_wrapper.h"
#include <jansson.h>

int main (int argc, char const *argv[])
{
	JanssonWrapper *jan = NULL;

	if (!isatty(STDIN_FILENO))
	{
	   jan = loadJson(stdin);

	   int numRows;
       int numCols;
       int start[2];
       int end[2];
       int withSolution;
       const char *wallsColor;
       const char *outputFormat;
       const char *outputFilename;

       int returnVal = json_unpack_ex(jan->data, &jan->error, JSON_STRICT, 
       			   "{s:i, s:i, s:[ii!], s:[ii!], s:b, s:s, s:s, s:s}", 
       			   "num-rows", &numRows, 
       			   "num-cols", &numCols,
       			   "start", &start[0], &start[1],
       			   "end", &end[0], &end[1],
       			   "with-solution", &withSolution,
       			   "walls-color", &wallsColor,
       			   "output-format", &outputFormat,
       			   "output-filename", &outputFilename);

       if (returnVal == -1)
       {
       	printf("%s\n", "Json parsing error.");
       	return EXIT_FAILURE;
       }

       printf("%s%s%s\n", "Value for key : ", "walls-color = ", wallsColor);
	   printf("%s%s%i\n", "Value for key : ", "num-rows = ", numRows);
	   printf("%s%s%i\n", "Value for key : ", "num-cols = ", numCols);
	   printf("%s%s%i\n", "Value for key : ", "with-solution = ", withSolution);
	   printf("%s%s%s\n", "Value for key : ", "output-format = ", outputFormat);
	   printf("%s%s%s\n", "Value for key : ", "output-filename = ", outputFilename);
	   printf("%s%s%i\n", "Value for key : ", "start (first element) = ", start[0]);
	   printf("%s%s%i\n", "Value for key : ", "start (second element) = ", start[1]);
	   printf("%s%s%i\n", "Value for key : ", "end (first element) = ", end[0]);
	   printf("%s%s%i\n", "Value for key : ", "end (second element) = ", end[1]);

	   // printf("%s%s%s\n", "Value for key : ", "walls-color = ", getString(jan, "walls-color"));
	   // printf("%s%s%i\n", "Value for key : ", "num-rows = ", getInt(jan, "num-rows"));
	   // printf("%s%s%s\n", "Value for key : ", "with-solution = ", getBool(jan, "with-solution") ? "true" : "false");
	   // printf("%s%s%i\n", "Value for key : ", "start (first element) = ", getIntArray(jan, "start")[0]);
	   // printf("%s%s%i\n", "Value for key : ", "start (second element) = ", getIntArray(jan, "start")[1]);
	   // printf("%s%s%i\n", "Value for key : ", "end (first element) = ", getIntArray(jan, "end")[0]);
	   // printf("%s%s%i\n", "Value for key : ", "end (second element) = ", getIntArray(jan, "end")[1]);
	}else{
		printf("%s\n", "No json file to process.");
	}

	if (jan != NULL)
		free(jan);	
	
	return EXIT_SUCCESS;	
}

