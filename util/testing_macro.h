#ifndef TEST_MACRO
#define TEST_MACRO

// If not condition, then failure, hence message
// Didnt want assert, failed tests needn't call abort()

#include <stdio.h>
#include <stdlib.h>

#define STRINGIZE(TEXT) #TEXT
#define STRING_LINE STRINGIZE(__LINE__)

#define test(EXPECTED_CONDITION, FAILURE_MESSAGE)\
if(!EXPECTED_CONDITION){\
    puts("File:"__FILE__ " Line:" STRING_LINE  #EXPECTED_CONDITION " : " FAILURE_MESSAGE);\
    exit(-1);\
}

#endif