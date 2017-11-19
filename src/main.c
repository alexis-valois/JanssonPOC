#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

int main (int argc, char const *argv[])
{
	printf("%s\n", "Trying to parse input stream...");
	json_error_t error;
	
	json_t* data = json_loadf(stdin, 0, &error);

	if(!data)
	{
	    fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
	    return 1;
	}

	const json_t* wallsColor = json_object_get(data, "walls-color");
    if(!json_is_string(wallsColor))
    {
    	fprintf(stderr, "error: walls-color is not a string.");
	    return 1;
    }

    printf("%s%s\n", "walls-color value is : ", json_string_value(wallsColor));

	return 0;
}