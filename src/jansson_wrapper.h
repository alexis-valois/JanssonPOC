#ifndef JANSSON_WRAPPER_H
#define JANSSON_WRAPPER_H

#include <jansson.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	json_error_t error;
	json_t* data;
}JanssonWrapper;

JanssonWrapper* loadJson(FILE* file);
const char* getString(JanssonWrapper* jan, const char* key);
int getInt(JanssonWrapper* jan, const char* key);
bool getBool(JanssonWrapper* jan, const char* key);
int* getIntArray(JanssonWrapper* jan, const char* key);
bool isJansonWrapperInitialized(JanssonWrapper* jan);

#endif