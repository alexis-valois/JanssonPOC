#include "jansson_wrapper.h"
#include <stdio.h>
#include <stdbool.h>

JanssonWrapper* loadJson(FILE* file)
{
	JanssonWrapper *jan = malloc(sizeof(JanssonWrapper));
	jan->data = json_loadf(file, 0, &jan->error);
	if(!jan->data)
	{
	    fprintf(stderr, "error: on line %d: %s\n", jan->error.line, jan->error.text);
	}
	return jan;
}

const char* getString(JanssonWrapper* jan, const char* key)
{
	if(isJansonWrapperInitialized(jan))
	{
	   const json_t* value = json_object_get(jan->data, key);
	   if(!json_is_string(value))
	   {
	      fprintf(stderr, "%s%s\n", key, " is not a string.");
		  return "";
	   }
	   return json_string_value(value);
	}

	return "";
}

int getInt(JanssonWrapper* jan, const char* key)
{
	if(isJansonWrapperInitialized(jan))
	{
	   const json_t* value = json_object_get(jan->data, key);
	   if(!json_is_number(value))
	   {
	      fprintf(stderr, "%s%s\n", key, " is not a number.");
		  return -1;
	   }
	   return json_integer_value(value);
	}

	return -1;
}

bool getBool(JanssonWrapper* jan, const char* key)
{
	if(isJansonWrapperInitialized(jan))
	{
	   const json_t* value = json_object_get(jan->data, key);
	   if(!json_is_boolean(value))
	   {
	      fprintf(stderr, "%s%s\n", key, " is not a bool.");
		  return false;
	   }
	   return json_boolean_value(value);
	}

	return false;
}

int* getIntArray(JanssonWrapper* jan, const char* key)
{
	int* finalArray = calloc(1, sizeof(int));
	if(isJansonWrapperInitialized(jan))
	{
	   const json_t* value = json_object_get(jan->data, key);
	   if(!json_is_array(value))
	   {
	      fprintf(stderr, "%s%s\n", key, " is not an array.");
		  return finalArray;
	   }

	   size_t arraySize = json_array_size(value);
	   finalArray = calloc(arraySize, sizeof(int));

	   for (int i = 0; i < arraySize; i++)
	   {
	   		json_t* currentValue = json_array_get(value, i);
	   		if(!json_is_number(currentValue))
		   	{
		       fprintf(stderr, "%s\n", "An array element is not a number.");
			   return finalArray;
		   	}
		   	finalArray[i] = json_integer_value(currentValue);
	   }

	}

	return finalArray;
}

bool isJansonWrapperInitialized(JanssonWrapper* jan)
{
	if(!jan->data)
	{
	    fprintf(stderr, "No json object loaded.\n");
	    return false;
	}

	return true;
}
